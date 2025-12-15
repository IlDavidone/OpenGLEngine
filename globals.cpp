#include "globals.h"

float vertices[] = {
    // back face (normal 0,0,-1)
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,  0.0f, 0.0f, -1.0f,
     0.5f, -0.5f, -0.5f,  1.0f, 0.0f,  0.0f, 0.0f, -1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,  0.0f, 0.0f, -1.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,  0.0f, 0.0f, -1.0f,
    -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,  0.0f, 0.0f, -1.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,  0.0f, 0.0f, -1.0f,

    // front face (normal 0,0,1)
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,  0.0f, 0.0f, 1.0f,
     0.5f, -0.5f,  0.5f,  1.0f, 0.0f,  0.0f, 0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,  0.0f, 0.0f, 1.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 1.0f,  0.0f, 0.0f, 1.0f,
    -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,  0.0f, 0.0f, 1.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,  0.0f, 0.0f, 1.0f,

    // left face (normal -1,0,0)
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,  -1.0f, 0.0f, 0.0f,
    -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,  -1.0f, 0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,  -1.0f, 0.0f, 0.0f,
    -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,  -1.0f, 0.0f, 0.0f,
    -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,  -1.0f, 0.0f, 0.0f,
    -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,  -1.0f, 0.0f, 0.0f,

    // right face (normal 1,0,0)
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,  1.0f, 0.0f, 0.0f,
     0.5f,  0.5f, -0.5f,  1.0f, 1.0f,  1.0f, 0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,  1.0f, 0.0f, 0.0f,
     0.5f, -0.5f, -0.5f,  0.0f, 1.0f,  1.0f, 0.0f, 0.0f,
     0.5f, -0.5f,  0.5f,  0.0f, 0.0f,  1.0f, 0.0f, 0.0f,
     0.5f,  0.5f,  0.5f,  1.0f, 0.0f,  1.0f, 0.0f, 0.0f,

     // bottom face (normal 0,-1,0)
     -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,  0.0f, -1.0f, 0.0f,
      0.5f, -0.5f, -0.5f,  1.0f, 1.0f,  0.0f, -1.0f, 0.0f,
      0.5f, -0.5f,  0.5f,  1.0f, 0.0f,  0.0f, -1.0f, 0.0f,
      0.5f, -0.5f,  0.5f,  1.0f, 0.0f,  0.0f, -1.0f, 0.0f,
     -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,  0.0f, -1.0f, 0.0f,
     -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,  0.0f, -1.0f, 0.0f,

     // top face (normal 0,1,0)
     -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,  0.0f, 1.0f, 0.0f,
      0.5f,  0.5f, -0.5f,  1.0f, 1.0f,  0.0f, 1.0f, 0.0f,
      0.5f,  0.5f,  0.5f,  1.0f, 0.0f,  0.0f, 1.0f, 0.0f,
      0.5f,  0.5f,  0.5f,  1.0f, 0.0f,  0.0f, 1.0f, 0.0f,
     -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,  0.0f, 1.0f, 0.0f,
     -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,  0.0f, 1.0f, 0.0f
};

unsigned int verticesSize = sizeof(vertices);

void Cube::draw(Shader& shader, VAO vao) {
    vao.Bind();

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, position);
    model = glm::rotate(model, glm::radians(rotationAngle), glm::vec3(0.0f, 1.0f, 0.0f));
    glUniformMatrix4fv(glGetUniformLocation(shader.ID, "model"), 1, GL_FALSE, glm::value_ptr(model));
    glDrawArrays(GL_TRIANGLES, 0, 36);

    vao.Unbind();
}
void Cube::positionCube(glm::vec3 newPosition) {
    position = newPosition;
}
void Cube::rotateCube(float angle) {
    rotationAngle += angle;
}

GLFWwindow* window = nullptr;

std::unique_ptr<std::vector<Cube>> cubePositions (new std::vector<Cube>);

Textures textures;

Mesh::Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices, std::vector<Textures> textures)
    : vertices(vertices), indices(indices), textures(textures)
{
    setupMesh();
}
void Mesh::setupMesh()
{
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int),
        &indices[0], GL_STATIC_DRAW);

    // positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

    // normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));

    // texcoords
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));

    glBindVertexArray(0);
}
void Mesh::Draw(Shader& shader)
{
    if (!textures.empty())
    {
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, textures[0].id);
        glUniform1i(glGetUniformLocation(shader.ID, "texture1"), 0);
    }

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}


unsigned int loadTexture(const char* path)
{
    unsigned int textureID;
    glGenTextures(1, &textureID);

    int width, height, nrComponents;
    unsigned char* data = stbi_load(path, &width, &height, &nrComponents, 0);
    if (data)
    {
        GLenum format;
        if (nrComponents == 1)
            format = GL_RED;
        else if (nrComponents == 3)
            format = GL_RGB;
        else if (nrComponents == 4)
            format = GL_RGBA;
        else
            format = GL_RGB; // fallback

        glBindTexture(GL_TEXTURE_2D, textureID);
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        stbi_image_free(data);
    }
    else
    {
        std::cout << "Failed to load texture: " << path << std::endl;
        stbi_image_free(data);
    }

    return textureID;
}

void Model::Draw(Shader& shader)
{
    for (unsigned int i = 0; i < meshes.size(); i++)
        meshes[i].Draw(shader);
}
void Model::loadModel(std::string path)
{
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(path, aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_CalcTangentSpace | aiProcess_OptimizeMeshes );
    if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode)
    {
        std::cout << "ERROR::ASSIMP::" << importer.GetErrorString() << std::endl;
        return;
    }
    directory = path.substr(0, path.find_last_of('/'));
    processNode(scene->mRootNode, scene);
}
void Model::processNode(aiNode* node, const aiScene* scene)
{
    for (unsigned int i = 0; i < node->mNumMeshes; i++)
    {
        aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
        meshes.push_back(processMesh(mesh, scene, nullptr));
    }
    for (unsigned int i = 0; i < node->mNumChildren; i++)
    {
        processNode(node->mChildren[i], scene);
    }
}

Mesh Model::processMesh(aiMesh* mesh, const aiScene* scene, const char* texturePath = nullptr)
{
    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;
    std::vector<Textures> textures;

    // Process vertices
    for (unsigned int i = 0; i < mesh->mNumVertices; i++)
    {
        Vertex vertex;
        vertex.Position = glm::vec3(mesh->mVertices[i].x, mesh->mVertices[i].y, mesh->mVertices[i].z);
        vertex.Normal = glm::vec3(mesh->mNormals[i].x, mesh->mNormals[i].y, mesh->mNormals[i].z);

        if (mesh->mTextureCoords[0])
            vertex.TexCoords = glm::vec2(mesh->mTextureCoords[0][i].x,
                mesh->mTextureCoords[0][i].y);
        else
            vertex.TexCoords = glm::vec2(0.0f, 0.0f);

        vertices.push_back(vertex);
    }

    // Process indices
    for (unsigned int i = 0; i < mesh->mNumFaces; i++)
    {
        aiFace face = mesh->mFaces[i];
        for (unsigned int j = 0; j < face.mNumIndices; j++)
            indices.push_back(face.mIndices[j]);
    }

    // Load one texture if path is provided
    if (texturePath)
    {
        Textures texture;
        texture.id = loadTexture(texturePath); // use your loadTexture function
        texture.path = texturePath;
        textures.push_back(texture);
    }

    return Mesh(vertices, indices, textures);
}

std::vector<glm::vec3> pointLightPositions {
        glm::vec3(0.7f,  0.2f,  2.0f),
        glm::vec3(2.3f, -3.3f, -4.0f),
        glm::vec3(-4.0f,  2.0f, -12.0f),
        glm::vec3(0.0f,  0.0f, -3.0f)
};

int framePerSeconds{};

glm::mat4 model = glm::rotate(glm::mat4(1.0f), glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));

glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f),
    glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(0.0f, 1.0f, 0.0f));

glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

glm::vec3 lightPos(0.0f, 1.2f, -4.0f);

bool showDemoWindow = false;
bool movingLightBulb = false;

float deltaTime = 0.0f;	// Time between current frame and last frame
float lastFrame = 0.0f;

float lightPosSpeed = 0.8f;

lightProperties lightProps = {
    glm::vec3(0.1f, 0.1f, 0.1f),
    glm::vec3(1.0f, 1.0f, 1.0f),
    glm::vec3(0.5f, 0.5f, 0.5f),
    32.0f
};