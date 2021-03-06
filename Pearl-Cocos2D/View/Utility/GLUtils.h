/*
 *   Copyright 2009, Maarten Billemont
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */

//
//  GLUtils.h
//  Pearl
//
//  Created by Maarten Billemont on 26/11/08.
//  Copyright 2008-2009, lhunath (Maarten Billemont). All rights reserved.
//

/*
#define glBindBuffer(m, b) \
    do { dbg(@"glBindBuffer(%s, %s)", #m, #b); glBindBuffer(m, b); GLCheck(__FILE__, __LINE__);     } while (0)
#define glBindTexture(m, n) \
    do { dbg(@"glBindTexture(%s, %s)", #m, #n ); glBindTexture(m, n); GLCheck(__FILE__, __LINE__);                               } while (0)
#define glBlendFunc(s, d) \
    do { dbg(@"glBlendFunc(%s, %s)", #s, #d ); glBlendFunc(s, d); GLCheck(__FILE__, __LINE__);                                   } while (0)
#define glBufferData(m, s, d, o) \
    do { dbg(@"glBufferData(%s, %s, %s, %s)", #m, #s, #d, #o); glBufferData(m, s, d, o); GLCheck(__FILE__, __LINE__);            } while (0)
#define glClear(m) \
    do { dbg(@"glClear(%s)", #m); glClear(m); GLCheck(__FILE__, __LINE__);                                                       } while (0)
#define glClearColor(r, g, b, a) \
    do { dbg(@"glClearColor(%s, %s, %s, %s)", #r, #g, #b, #a); glClearColor(r, g, b, a); GLCheck(__FILE__, __LINE__);            } while (0)
#define glColor4ub(r, g, b, a) \
    do { dbg(@"glColor4ub(%s, %s, %s, %s)", #r, #g, #b, #a); glColor4ub(r, g, b, a); GLCheck(__FILE__, __LINE__);                } while (0)
#define glColorMask(r, g, b, a) \
    do { dbg(@"glColorMask(%s, %s, %s, %s)", #r, #g, #b, #a); glColorMask(r, g, b, a); GLCheck(__FILE__, __LINE__);              } while (0)
#define glColorPointer(x, y, z, c) \
    do { dbg(@"glColorPointer(%s, %s, %s, %s)", #x, #y, #z, #c); glColorPointer(x, y, z, c); GLCheck(__FILE__, __LINE__);        } while (0)
#define glDeleteBuffers(c, b) \
    do { dbg(@"glDeleteBuffers(%s, %s)", #c, #b); glDeleteBuffers(c, b); GLCheck(__FILE__, __LINE__);                            } while (0)
#define glDisable(m) \
    do { dbg(@"glDisable(%s)", #m); glDisable(m); GLCheck(__FILE__, __LINE__);                                                   } while (0)
#define glDisableClientState(m) \
    do { dbg(@"glDisableClientState(%s)", #m); glDisableClientState(m); GLCheck(__FILE__, __LINE__);                             } while (0)
#define glDrawArrays(x, y, z) \
    do { dbg(@"glDrawArrays(%s, %s, %s)", #x, #y, #z); glDrawArrays(x, y, z); GLCheck(__FILE__, __LINE__);                       } while (0)
#define glDrawElements(m, c, s, o) \
    do { dbg(@"glDrawElements(%s, %s, %s, %s)", #m, #c, #s, #o); glDrawElements(m, c, s, o); GLCheck(__FILE__, __LINE__);        } while (0)
#define glEnable(m) \
    do { dbg(@"glEnable(%s)", #m); glEnable(m); GLCheck(__FILE__, __LINE__);                                                     } while (0)
#define glEnableClientState(m) \
    do { dbg(@"glEnableClientState(%s)", #m); glEnableClientState(m); GLCheck(__FILE__, __LINE__);                               } while (0)
#define glGenBuffers(c, b) \
    do { dbg(@"glGenBuffers(%s, %s)", #c, #b); glGenBuffers(c, b); GLCheck(__FILE__, __LINE__);                                  } while (0)
#define glIsEnabled(m) \
    glIsEnabled(m); dbg(@"glIsEnabled(%s)", #m); GLCheck(__FILE__, __LINE__);
#define glLineWidth(w) \
    do { dbg(@"glLineWidth(%s)", #w); glLineWidth(w); GLCheck(__FILE__, __LINE__);                                               } while (0)
#define glPointSize(x) \
    do { dbg(@"glPointSize(%s)", #x); glPointSize(x); GLCheck(__FILE__, __LINE__);                                               } while (0)
#define glPointSizePointerOES(m, s, d) \
    do { dbg(@"glPointSizePointerOES(%s, %s, %s)", #m, #s, #d); glPointSizePointerOES(m, s, d); GLCheck(__FILE__, __LINE__);     } while (0)
#define glScissor(x1, y1, x2, y2) \
    do { dbg(@"glScissor(%s, %s, %s, %s)", #x1, #y1, #x2, #y2); glScissor(x1, y1, x2, y2); GLCheck(__FILE__, __LINE__);          } while (0)
#define glTexCoordPointer(s, t, i, d) \
    do { dbg(@"glTexCoordPointer(%s, %s, %s, %s)", #s, #t, #i, #d); glTexCoordPointer(s, t, i, d); GLCheck(__FILE__, __LINE__);  } while (0)
#define glTexParameterf(m, w, r) \
    do { dbg(@"glTexParameterf(%s, %s, %s)", #m, #w, #r); glTexParameterf(m, w, r); GLCheck(__FILE__, __LINE__);                 } while (0)
#define glTranslatef(x, y, z) \
    do { dbg(@"glTranslatef(%s, %s, %s)", #x, #y, #z); glTranslatef(x, y, z); GLCheck(__FILE__, __LINE__);                       } while (0)
#define glVertexPointer(x, y, z, p) \
    do { dbg(@"glVertexPointer(%s, %s, %s, %s)", #x, #y, #z, #p); glVertexPointer(x, y, z, p); GLCheck(__FILE__, __LINE__);      } while (0)
*/


int GLCheck(char *file, int line);

/**
 * GL types
 */
typedef struct Vertex {
	CGPoint p;
    ccColor4B c;
} Vertex;

//! helper function that converts a ccColor4B into a ccColor3B by dropping the alpha value.
static inline ccColor4B
ccc3to4(const ccColor3B color)
{
	ccColor4B c = { color.r, color.g, color.b, UCHAR_MAX };
	return c;
}

//! helper function that converts a ccColor4B into a ccColor3B by dropping the alpha value.
static inline ccColor3B
ccc4to3(const ccColor4B color)
{
	ccColor3B c = { color.r, color.g, color.b };
	return c;
}

//! helper function that creates an ccColor4B type from a long
static inline ccColor4B
ccc4l(const long color)
{
    GLubyte *components = (GLubyte *)&color;
	ccColor4B c = { components[3], components[2], components[1], components[0] };
	return c;
}

//! helper function that creates an ccColor3B type from a long
static inline ccColor3B
ccc3l(const long color)
{
    GLubyte *components = (GLubyte *)&color;
	ccColor3B c = { components[2], components[1], components[0] };
	return c;
}

//! helper function that creates an ccColor4F type
static inline ccColor4F
ccc4f(const float r, const float g, const float b, const float a)
{
	ccColor4F c = { r, g, b, a };
	return c;
}

//! helper function that creates an ccColor4F type
static inline ccColor4F
ccc4fl(const long color)
{
    GLubyte *components = (GLubyte *)&color;
	return ccc4f(components[3], components[2], components[1], components[0]);
}

//! lighten the color by a ratio, 0 being no change, 1 turning it white and -1 turning it black.
static inline ccColor3B
ccc3lighten(const ccColor3B color, float lightRatio)
{
	ccColor3B c = {
            MAX(0, MIN(UCHAR_MAX, color.r + UCHAR_MAX * lightRatio)),
            MAX(0, MIN(UCHAR_MAX, color.g + UCHAR_MAX * lightRatio)),
            MAX(0, MIN(UCHAR_MAX, color.b + UCHAR_MAX * lightRatio)),
    };

	return c;
}

//! lighten the color by a ratio, 0 being no change, 1 turning it white and -1 turning it black.
static inline ccColor4B
ccc4lighten(const ccColor4B color, float lightRatio)
{
	ccColor4B c = {
            MAX(0, MIN(UCHAR_MAX, color.r + UCHAR_MAX * lightRatio)),
            MAX(0, MIN(UCHAR_MAX, color.g + UCHAR_MAX * lightRatio)),
            MAX(0, MIN(UCHAR_MAX, color.b + UCHAR_MAX * lightRatio)),
            color.a
    };

	return c;
}

//! lighten the color by a ratio, 0 being no change, 1 turning it white and -1 turning it black.
static inline ccColor3B
ccc3shade(const ccColor3B color, const ccColor3B shade, float lightRatio)
{
	ccColor3B c = {
        MIN(UCHAR_MAX, color.r * (1 - lightRatio) + shade.r * lightRatio),
        MIN(UCHAR_MAX, color.g * (1 - lightRatio) + shade.g * lightRatio),
        MIN(UCHAR_MAX, color.b * (1 - lightRatio) + shade.b * lightRatio),
    };
    
	return c;
}

//! lighten the color by a ratio, 0 being no change, 1 turning it white and -1 turning it black.
static inline ccColor4B
ccc4shade(const ccColor4B color, const ccColor4B shade, float lightRatio)
{
	ccColor4B c = {
        MIN(UCHAR_MAX, color.r * (1 - lightRatio) + shade.r * lightRatio),
        MIN(UCHAR_MAX, color.g * (1 - lightRatio) + shade.g * lightRatio),
        MIN(UCHAR_MAX, color.b * (1 - lightRatio) + shade.b * lightRatio),
        color.a
    };
    
	return c;
}

void IndicateInSpaceOf(const CGPoint point, const CCNode* node);
void DrawIndicators(void);

void DrawPointsAt(const CGPoint* points, const NSUInteger count, const ccColor4B color);
void DrawPoints(const CGPoint* points, const ccColor4B* colors, const NSUInteger n);

void DrawLinesTo(const CGPoint from, const CGPoint* to, const NSUInteger count, const ccColor4B color, const CGFloat width);
void DrawLines(const CGPoint* points, const ccColor4B* colors, const NSUInteger n, const CGFloat width);

void DrawBoxFrom(const CGPoint from, const CGPoint to, const ccColor4B fromColor, const ccColor4B toColor);

void DrawBorderFrom(const CGPoint from, const CGPoint to, const ccColor4B color, const CGFloat width);

/** Apply glScissor for the given coordinates in the given node's space. */
void Scissor(const CCNode* inNode, const CGPoint from, const CGPoint to);
