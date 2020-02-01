#pragma once

#include "../Scene.hpp"
#include "Model.hpp"
#include "material/Material.hpp"

#include "../chromaray.hpp"

class Renderer {
public:
	Renderer(Scene* scene);

	void render(Model& model, Material& material);

private:
	Scene* m_Scene;
};