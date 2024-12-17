#include "TextRenderer.h"


void TextRenderer::renderText(const std::string& text, float x, float y, float scale, const Vec3& colour) {
    glPushMatrix();
    glTranslatef(x,y,0.0f);
    glScalef(scale, scale, 1.0f);
    glColor3f(colour.r, colour.g, colour.b);

    for (size_t i=0; i<text.length(); ++i) {

    }

    glPopMatrix();
}
