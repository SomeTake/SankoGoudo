#include "FieldController.h"
#include "Ground.h"

FieldController::FieldController()
{
	ground = new Ground();
}

FieldController::~FieldController()
{
	SAFE_DELETE(ground);
}

void FieldController::Update()
{
	ground->Update();
}

void FieldController::Draw()
{
	ground->Draw();
}
