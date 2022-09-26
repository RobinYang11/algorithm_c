/**
* Include GLUS. Needed OpenGL, OpenGL ES or OpenVG headers will be included depending on the build profile.
*/
#include "GL/glus.h"

/**
* Function for initialization.
*
* @return GLUS_TRUE when initalization succeeded, otherwise GLUS_FALSE and the application will exit.
*/
GLUSboolean init(GLUSvoid)
{
    // The background will be just cleared with blue color.
    glClearColor(0.0f, 0.0f, 1.0f, 0.0f);

    return GLUS_TRUE;
}

/**
* Function is called before first update and every time when the window is resized.
*
* @param width  The width of the window.
* @param height The height of the window.
*/
GLUSvoid reshape(GLUSint width, GLUSint height)
{
    // Set the viewport depending on the width and height of the window.
    glViewport(0, 0, width, height);
}

/**
* Function to update and render content. Swapping of the buffers is automatically done.
*
* @param time The passed / delta time from last frame.
*
* @return GLUS_TRUE for continuing, GLUS_FALSE to exit the application.
*/
GLUSboolean update(GLUSfloat time)
{
    // Now, the background is painted blue.
    glClear(GL_COLOR_BUFFER_BIT);

    return GLUS_TRUE;
}

/**
* Function to clean up things.
*/
GLUSvoid terminate(GLUSvoid)
{
    // No resources have to be freed in this case.
}

/**
* Main entry point.
*/
int main(int argc, char* argv[])
{
    // Parameters for the used window surface. See EGL man pages for more info.
    EGLint eglConfigAttributes[] = {
        EGL_RED_SIZE, 8,
        EGL_GREEN_SIZE, 8,
        EGL_BLUE_SIZE, 8,
        EGL_DEPTH_SIZE, 0,
        EGL_STENCIL_SIZE, 0,
        EGL_RENDERABLE_TYPE, EGL_OPENGL_BIT,
        EGL_NONE
    };

    // Parameters for the used context. See EGL man pages for more info.
    EGLint eglContextAttributes[] = {
        EGL_CONTEXT_MAJOR_VERSION, 3,
        EGL_CONTEXT_MINOR_VERSION, 2,
        EGL_CONTEXT_OPENGL_FORWARD_COMPATIBLE, EGL_TRUE,
        EGL_CONTEXT_OPENGL_PROFILE_MASK, EGL_CONTEXT_OPENGL_CORE_PROFILE_BIT,
        EGL_NONE
    };

    glusWindowSetInitFunc(init);

    glusWindowSetReshapeFunc(reshape);

    glusWindowSetUpdateFunc(update);

    glusWindowSetTerminateFunc(terminate);

    // Create the used window. See GLUS man pages for different parameters.
    if (!glusWindowCreate("GLUS Example Window", 640, 480, GLUS_FALSE, GLUS_FALSE, eglConfigAttributes, eglContextAttributes))
    {
        return -1;
    }

    // Enter the update render loop. See below state machine for more information.
    glusWindowRun();

    return 0;
}