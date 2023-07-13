#include "SelectionEffect.h"

#include <Unigine.h>

void SelectionEffect::effect_logic()
{
	PlayerPtr player = Game::getPlayer();

	TexturePtr screen_color = RenderState::getScreenColorTexture();
	MaterialPtr selection_material = Materials::findManualMaterial("selection");
	if (selection == nullptr || screen_color == nullptr || selection_material == nullptr)
		return;

	if (Renderer::isNode() != false || Renderer::isShadow() != false || Renderer::isReflection() != false)
		return;

	int width = RenderState::getWidth();
	int height = RenderState::getHeight();

	RenderTargetPtr render_target = Render::getTemporaryRenderTarget();
	TexturePtr depth = Render::getTemporaryTexture2D(width, height, Texture::FORMAT_D32FS8, Texture::FORMAT_USAGE_RENDER | Texture::SAMPLER_FILTER_POINT, "Selection depth");

	// Render depth buffer for selected objects
	Renderer::saveState();
	RenderState::saveState();
	render_target->bindDepthTexture(depth);
	render_target->enable();
	{
		RenderState::clearBuffer(RenderState::BUFFER_DEPTH, Math::vec4_zero);

		CameraPtr camera = player->getCamera();
		for (int i = 0; i < selection->getNumSurfaces(); i++)
		{
			Renderer::setModelview(camera->getModelview());
			RenderState::setDepthFunc(RenderState::DEPTH_GEQUAL);

			if (selection->getViewportMask(i) & camera->getViewportMask())
				selection->render(Render::PASS_DEPTH_PRE_PASS, i);
		}
	}
	render_target->disable();
	render_target->unbindAll();
	RenderState::restoreState();
	Renderer::restoreState();

	RenderState::saveState();
	{
		// Composite outline to screen color
		render_target->bindColorTexture(0, screen_color);
		render_target->enable();
		{
			RenderState::setBlendFunc(RenderState::BLEND_SRC_ALPHA, RenderState::BLEND_ONE_MINUS_SRC_ALPHA, RenderState::BLEND_OP_ADD);

			int num = selection_material->findTexture("selection_depth");
			selection_material->setTexture(num, depth);
			{
				selection_material->renderScreen("render_outline");
			}
			selection_material->setTexture(num, nullptr);
		}
		render_target->disable();
		render_target->unbindAll();
	}
	RenderState::restoreState();

	Render::releaseTemporaryTexture(depth);

	Render::releaseTemporaryRenderTarget(render_target);
}
