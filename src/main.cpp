#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <GLFW/glfw3.h>

#include <stdio.h>

#include "config.h"

GLFWwindow *window;

void init()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE, NULL, NULL);
    if (window == NULL)
    {
        glfwTerminate();
        return;
    }
    glfwMakeContextCurrent(window);

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");
}

void showMenuBar()
{
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("Archivo"))
        {
            if (ImGui::MenuItem("Nuevo"))
            {
                printf("Se ha seleccionado 'Nuevo'\n");
            }
            if (ImGui::MenuItem("Abrir"))
            {
            }
            ImGui::EndMenu();
        }

        if (ImGui::BeginMenu("Editar"))
        {
            if (ImGui::MenuItem("Copiar"))
            {
                printf("Se ha seleccionado 'Copiar'\n");
            }
            if (ImGui::MenuItem("Pegar"))
            {
                printf("Se ha seleccionado 'Pegar'\n");
            }
            ImGui::EndMenu();
        }

        ImGui::EndMainMenuBar();
    }
}

int main()
{

    init();

    while (!glfwWindowShouldClose(window))
    {
        // Procesar eventos
        glfwPollEvents();

        // Limpiar pantalla
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Mostrar menu bar
        showMenuBar();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Intercambiar buffers
        glfwSwapBuffers(window);
    }

    // Limpieza
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}