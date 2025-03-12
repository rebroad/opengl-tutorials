//------- Ignore this ----------
#include<filesystem>
namespace fs = std::filesystem;
//------------------------------

#include"Model.h"
#include <glm/gtc/type_ptr.hpp>


const unsigned int width = 800;
const unsigned int height = 800;


int main()
{
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what version of OpenGL we are using 
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Create a GLFWwindow object of 800 by 800 pixels, naming it "YoutubeOpenGL"
	GLFWwindow* window = glfwCreateWindow(width, height, "YoutubeOpenGL", NULL, NULL);
	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();
	// Specify the viewport of OpenGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800, y = 800
	glViewport(0, 0, width, height);





	// Generates Shader object using shaders default.vert and default.frag
	Shader shaderProgram("default.vert", "default.frag");

	// Check if shader program is valid
	GLint isLinked = 0;
	glGetProgramiv(shaderProgram.ID, GL_LINK_STATUS, &isLinked);
	if (isLinked == GL_FALSE) {
		GLint maxLength = 0;
		glGetProgramiv(shaderProgram.ID, GL_INFO_LOG_LENGTH, &maxLength);
		std::vector<GLchar> infoLog(maxLength);
		glGetProgramInfoLog(shaderProgram.ID, maxLength, &maxLength, &infoLog[0]);
		std::cout << "Shader linking error: " << std::string(infoLog.begin(), infoLog.end()) << std::endl;
		return -1;
	}

	// Take care of all the light related things
	glm::vec4 lightColor = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f);
	glm::vec3 lightPos = glm::vec3(2.0f, 4.0f, -1.0f);
	float lightMovementRadius = 5.0f;  // Increased radius
	glm::mat4 lightModel = glm::mat4(1.0f);
	lightModel = glm::translate(lightModel, lightPos);

	// Vertices for a cube to represent the light source
	float lightVertices[] = {
		// Position coordinates
		-0.5f, -0.5f,  0.5f,
		 0.5f, -0.5f,  0.5f,
		 0.5f,  0.5f,  0.5f,
		-0.5f,  0.5f,  0.5f,
		-0.5f, -0.5f, -0.5f,
		 0.5f, -0.5f, -0.5f,
		 0.5f,  0.5f, -0.5f,
		-0.5f,  0.5f, -0.5f
	};

	// Indices for the cube vertices
	unsigned int lightIndices[] = {
		0, 1, 2,
		2, 3, 0,
		0, 4, 7,
		7, 3, 0,
		3, 7, 6,
		6, 2, 3,
		2, 6, 5,
		5, 1, 2,
		1, 5, 4,
		4, 0, 1,
		4, 5, 6,
		6, 7, 4
	};

	// Create VAO, VBO, and EBO for the light cube
	unsigned int lightVAO, lightVBO, lightEBO;
	glGenVertexArrays(1, &lightVAO);
	glGenBuffers(1, &lightVBO);
	glGenBuffers(1, &lightEBO);

	glBindVertexArray(lightVAO);
	glBindBuffer(GL_ARRAY_BUFFER, lightVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(lightVertices), lightVertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, lightEBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(lightIndices), lightIndices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	// Create a basic shader for the light cube
	Shader lightShader("light.vert", "light.frag");
	
	if (!lightShader.ID) {
		std::cout << "Failed to create light shader program!" << std::endl;
		return -1;
	}

	// Check if light shader program is valid
	GLint isLightShaderLinked = 0;
	glGetProgramiv(lightShader.ID, GL_LINK_STATUS, &isLightShaderLinked);
	if (isLightShaderLinked == GL_FALSE) {
		GLint maxLength = 0;
		glGetProgramiv(lightShader.ID, GL_INFO_LOG_LENGTH, &maxLength);
		std::vector<GLchar> infoLog(maxLength);
		glGetProgramInfoLog(lightShader.ID, maxLength, &maxLength, &infoLog[0]);
		std::cout << "Light shader linking error: " << std::string(infoLog.begin(), infoLog.end()) << std::endl;
		return -1;
	}

	shaderProgram.Activate();
	
	// Check for uniform location errors
	GLint lightColorLoc = glGetUniformLocation(shaderProgram.ID, "lightColor");
	GLint lightPosLoc = glGetUniformLocation(shaderProgram.ID, "lightPos");
	GLint camPosLoc = glGetUniformLocation(shaderProgram.ID, "camPos");
	
	if (lightColorLoc == -1 || lightPosLoc == -1 || camPosLoc == -1) {
		std::cout << "Warning: Failed to locate uniform(s): " 
			<< (lightColorLoc == -1 ? "lightColor " : "") 
			<< (lightPosLoc == -1 ? "lightPos " : "") 
			<< (camPosLoc == -1 ? "camPos" : "") << std::endl;
	}
	
	glUniform4f(lightColorLoc, lightColor.x, lightColor.y, lightColor.z, lightColor.w);
	// Initial light position set - will be updated in the loop



	

	// Enables the Depth Buffer and choses which depth function to use
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	// Creates camera object
	Camera camera(width, height, glm::vec3(0.0f, 0.0f, 2.0f));


	/*
	* I'm doing this relative path thing in order to centralize all the resources into one folder and not
	* duplicate them between tutorial folders. You can just copy paste the resources from the 'Resources'
	* folder and then give a relative path from this folder to whatever resource you want to get to.
	* Also note that this requires C++17, so go to Project Properties, C/C++, Language, and select C++17
	*/
	std::string parentDir = (fs::current_path().fs::path::parent_path()).string();
	std::string groundPath = "/Resources/YoutubeOpenGL 14 - Depth Buffer/models/ground/scene.gltf";
	std::string treesPath = "/Resources/YoutubeOpenGL 14 - Depth Buffer/models/trees/scene.gltf";

	// Load in models
	Model ground((parentDir + groundPath).c_str());
	Model trees((parentDir + treesPath).c_str());



	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		// Clean the back buffer and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Handles camera inputs
		camera.Inputs(window);
		// Updates and exports the camera matrix to the Vertex Shader
		camera.updateMatrix(45.0f, 0.1f, 100.0f);

		// Set camera position uniform
		glm::vec3 camPosition = camera.Position;
		glUniform3f(camPosLoc, camPosition.x, camPosition.y, camPosition.z);
		
		// Make the light move in a circle
	float timeValue = glfwGetTime();
	lightPos.x = cos(timeValue) * lightMovementRadius;
	lightPos.z = sin(timeValue) * lightMovementRadius;
	lightPos.y = 4.0f;  // Keep the light elevated
	glUniform3f(lightPosLoc, lightPos.x, lightPos.y, lightPos.z);

		// Draw models
		ground.Draw(shaderProgram, camera);
		trees.Draw(shaderProgram, camera);

		// Draw the light cube
		lightShader.Activate();
		
		// Save current OpenGL state
		GLboolean depthTest;
		glGetBooleanv(GL_DEPTH_TEST, &depthTest);
		
		// Ensure depth testing is enabled
		glEnable(GL_DEPTH_TEST);
		
		// Update matrices
		lightModel = glm::mat4(1.0f);
		lightModel = glm::translate(lightModel, lightPos);
		glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "model"), 1, GL_FALSE, glm::value_ptr(lightModel));
		glUniformMatrix4fv(glGetUniformLocation(lightShader.ID, "camMatrix"), 1, GL_FALSE, glm::value_ptr(camera.cameraMatrix));
		
		// Draw the light cube
		glBindVertexArray(lightVAO);
		glDrawElements(GL_TRIANGLES, sizeof(lightIndices)/sizeof(int), GL_UNSIGNED_INT, 0);
		
		// Restore previous depth test state
		if (!depthTest) {
			glDisable(GL_DEPTH_TEST);
		}

		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);
		// Take care of all GLFW events
		glfwPollEvents();
	}



	// Delete all the objects we've created
	shaderProgram.Delete();
	// Delete window before ending the program
	glfwDestroyWindow(window);
	// Terminate GLFW before ending the program
	glfwTerminate();
	return 0;
}