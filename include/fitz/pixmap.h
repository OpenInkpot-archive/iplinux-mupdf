/*
pixmaps have n components per pixel. the first is always alpha.
premultiplied alpha when rendering, but non-premultiplied for colorspace
conversions and rescaling.
*/

typedef struct fz_pixmap_s fz_pixmap;
typedef unsigned char fz_sample;

struct fz_pixmap_s
{
	int x, y, w, h, n;
	fz_sample *samples;
};

fz_error *fz_newpixmap(fz_pixmap **mapp, int x, int y, int w, int h, int n);
void fz_debugpixmap(fz_pixmap *map);
void fz_clearpixmap(fz_pixmap *map);
void fz_freepixmap(fz_pixmap *map);

fz_error *fz_convertpixmap(fz_pixmap **dstp, fz_pixmap *src, fz_colorspace *srcs, fz_colorspace *dsts);
fz_error *fz_scalepixmap(fz_pixmap **dstp, fz_pixmap *src, int xdenom, int ydenom);

void fz_blendover(fz_pixmap *src, fz_pixmap *dst);
void fz_blendmask(fz_pixmap *dst, fz_pixmap *color, fz_pixmap *shape);
