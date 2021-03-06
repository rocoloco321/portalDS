#ifndef BIGBUTTON_H
#define BIGBUTTON_H

#define NUMBIGBUTTONS (16)

typedef struct
{
	room_struct* room;
	rectangle_struct* surface;
	activator_struct activator;
	modelInstance_struct modelInstance;
	vect3D position;
	bool active;
	bool used;
	u8 id;
}bigButton_struct;

void initBigButtons(void);
void freeBigButtons(void);
bigButton_struct* createBigButton(room_struct* r, vect3D position);
void drawBigButtons(void);
void updateBigButtons(void);

#endif
