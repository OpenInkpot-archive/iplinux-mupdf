typedef struct fz_renderer_s fz_renderer;

enum { FZ_RNONE, FZ_ROVER, FZ_RMASK };

struct fz_renderer_s
{
    fz_colorspace *model;
    fz_glyphcache *cache;
    fz_gel *gel;
    fz_ael *ael;
    int mode;
    int x, y, w, h;
    fz_pixmap *tmp;
    fz_pixmap *acc;
    unsigned char r, g, b;
};

fz_error *fz_newrenderer(fz_renderer **gcp, fz_colorspace *pcm);
void fz_freerenderer(fz_renderer *gc);

fz_error *fz_renderover(fz_renderer *gc, fz_overnode *over, fz_matrix ctm);
fz_error *fz_rendermask(fz_renderer *gc, fz_masknode *mask, fz_matrix ctm);
fz_error *fz_rendertransform(fz_renderer *gc, fz_transformnode *xform, fz_matrix ctm);
fz_error *fz_rendertext(fz_renderer *gc, fz_textnode *text, fz_matrix ctm);
fz_error *fz_rendernode(fz_renderer *gc, fz_node *node, fz_matrix ctm);
fz_error *fz_rendertree(fz_pixmap **out, fz_renderer *gc, fz_tree *tree, fz_matrix ctm, fz_rect bbox);
