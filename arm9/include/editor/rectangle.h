#ifndef __RECTANGLE9__
#define __RECTANGLE9__

typedef enum
{
	EMPTY,
	RECTANGLE,
	HORIZONTAL,
	VERTICAL
}treeNode_type;

typedef struct treeNode_struct
{
	struct treeNode_struct* son[2];
	treeNode_type type;
	short data;
}treeNode_struct;

typedef struct
{
	treeNode_struct* root;
	short width, height;
}tree_struct;

typedef struct
{
	vect2D position, size;
	lightMapCoordinates_struct* real;
	bool rot;
}rectangle2D_struct;

typedef struct listCell2D_struct
{
	rectangle2D_struct data;
	struct listCell2D_struct* next;
}listCell2D_struct;

typedef struct
{
	listCell2D_struct* first;
	int surface;
	int num;
}rectangle2DList_struct;

void initRectangle2DList(rectangle2DList_struct* l);
void insertRectangle2DList(rectangle2DList_struct* l, rectangle2D_struct rec);
void packRectangles(rectangle2DList_struct* l, short w, short h);
bool packRectanglesSize(rectangle2DList_struct* l, short* w, short* h);
void freeRectangle2DList(rectangle2DList_struct* l);

void fillRectangle(u8* data, int w, int h, vect2D* pos, vect2D* size, u8 mask);
void getMaxRectangle(u8* data, u8 val, int w, int h, vect2D* pos, vect2D* size);
bool collideLineRectangle(rectangle_struct* rec, vect3D o, vect3D v, int32 d, int32* kk, vect3D* ip);
bool collideLineConvertedRectangle(vect3D n, vect3D p, vect3D s, vect3D o, vect3D v, int32 d, int32* kk, vect3D* ip);
vect3D getClosestPointRectangleStruct(rectangle_struct* rec, vect3D o);
vect3D getClosestPointRectangle(vect3D p, vect3D s, vect3D o);

materialSlice_struct* bindMaterial(material_struct* m, rectangle_struct* rec, int32* t, vect3D* v,bool DL);

#endif
