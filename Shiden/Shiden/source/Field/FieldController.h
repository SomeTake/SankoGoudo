#ifndef _FIELDCONTROLLER_H_
#define _FIELDCONTROLLER_H_

class Ground;
class FieldController
{
public:
	FieldController();
	~FieldController();

	void Update();
	void Draw();

private:
	Ground* ground;
};

#endif
