#ifndef FORWARD_AMBIENT_LIGHT_SHADER_H
#define FORWARD_AMBIENT_LIGHT_SHADER_H

#include "Shader.h"
#include "../Components/LightEmitter.h"

class ForwardAmbientLightShader : public Shader {
public:
	ForwardAmbientLightShader(const std::string& fileName) { init(fileName); }

	void update(Matrix4f& matrix, Matrix4f& modelMatrix, LightEmitter& ambient, Vector4f& eyeTransformed) {
		glUniformMatrix4fv(uniforms["mvp"], 1, GL_FALSE, &(matrix(0, 0)));
		glUniformMatrix4fv(uniforms["modelMatrix"], 1, GL_FALSE, &(modelMatrix(0, 0)));
		glUniform1f(uniforms["light.intensity"], ambient.intensity);
		glUniform3fv(uniforms["light.color"], 1, &(ambient.color.x()));
		glUniform3fv(uniforms["viewPos"], 1, &(eyeTransformed.x()));

		// Textures
	}

	void updateTextures() {
		glUniform1i(textures["albedoMap"].uniformLocation, 0);
		glUniform1i(textures["normalMap"].uniformLocation, 1);
		glUniform1i(textures["specularMap"].uniformLocation, 2);
		glUniform1i(textures["aoMap"].uniformLocation, 3);
		glUniform1i(textures["emissionMap"].uniformLocation, 4);

		glUniform1i(textures["skyBoxLod0"].uniformLocation, 5);
		glUniform1i(textures["skyBoxLod1"].uniformLocation, 6);
		glUniform1i(textures["skyBoxLod2"].uniformLocation, 7);
		glUniform1i(textures["skyBoxLod3"].uniformLocation, 8);

		std::cout <<
			"glUniform1i(" << textures["skyBoxLod0"].uniformLocation << ", 5);" << std::endl <<
			"glUniform1i(" << textures["skyBoxLod1"].uniformLocation << ", 6);" << std::endl <<
			"glUniform1i(" << textures["skyBoxLod2"].uniformLocation << ", 7);" << std::endl <<
			"glUniform1i(" << textures["skyBoxLod3"].uniformLocation << ", 8);" << std::endl;
	}

	void addAttributes() override {
		addAttribut("position", Vertex::AttibLocation::POSITION);
		addAttribut("normal", Vertex::AttibLocation::NORMAL);
		addAttribut("uv", Vertex::AttibLocation::TEXTURECOORD);
		addAttribut("tangent", Vertex::AttibLocation::TANGENT);
	}

	void addUniforms() override{
		addUniform("mvp");
		addUniform("modelMatrix");
		addUniform("light.intensity");
		addUniform("light.color");
		addUniform("viewPos");

		addTexture("albedoMap");
		addTexture("normalMap");
		addTexture("specularMap");
		addTexture("aoMap");
		addTexture("emissionMap");

		addTexture("skyBoxLod0");
		addTexture("skyBoxLod1");
		addTexture("skyBoxLod2");
		addTexture("skyBoxLod3");
	}
};

#endif /* defined(FORWARD_AMBIENT_LIGHT_SHADER_H) */