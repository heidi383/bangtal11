#include <bangtal>
using namespace bangtal;

int main()
{
	auto room1 = Scene::create("룸1", "Images/방배경.jpg");
	auto room2 = Scene::create("룸2", "Images/배경-2.png");

	auto open1 = false;
	auto door1 = Object::create("Images/문-오른쪽-닫힘.png", room1, 800, 200);
	door1->setOnMouseCallback([&](auto object, int x, int y, MouseAction action)-> bool {
		if (open1 == true)
		{
			room2->enter();
		}
		else
		{
			door1->setImage("Images./문-오른쪽-열림.png");
			open1 = true;
		}
		return true;
		});


	auto door2 = Object::create("Images/문-왼쪽-열림.png", room2, 320, 270);
	auto door3 = Object::create("Images/문-오른쪽-닫힘.png", room2, 800, 282);
	door2->setOnMouseCallback([&](auto object, int x, int y, MouseAction action)-> bool {
		room1->enter();
		return true;
		});


	auto open2 = false, locked = true;
	door3->setOnMouseCallback([&](auto object, int x, int y, MouseAction action)-> bool {
		if (locked)
		{
			showMessage("비빌번호: 룸1과 룸2에 있는 러버덕의 개수");
		}
		else if (open2 == true)
		{
			endGame();
		}
		else
		{
			door3->setImage("Images./문-오른쪽-열림.png");
			open2 = true;
		}
		return true;
		});


	auto closet = Object::create("Images./옷장.jpg", room1, 750, 200);
	closet->setScale(0.6f);
	closet->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		if (action == MouseAction::MOUSE_DRAG_LEFT) {
			closet->locate(room1, 580, 200);
		}
		else if (action == MouseAction::MOUSE_DRAG_RIGHT) {
			closet->locate(room1, 920, 200);
		}
		return true;
		});

	auto duck1 = Object::create("Images./러버덕정면.png", room1, 100, 90);
	duck1->setScale(0.3f);
	auto duck2 = Object::create("Images./러버덕측면.png", room2, 150.150);
	duck2->setScale(0.5f);
	auto duck3 = Object::create("Images./액자러버덕.png", room1, 520, 400);
	duck3->setScale(0.4f);
	auto duck5 = Object::create("Images./선반 러버덕.png", room2, 1000, 150);
	duck5->setScale(0.3f);

	auto keypad = Object::create("Images./키패드.png", room2, 750, 420);
	keypad->setOnMouseCallback([&](auto object, int x, int y, MouseAction action)-> bool {
		showKeypad("6", door3);
		return true;
		});

	door3->setOnKeypadCallback([&](ObjectPtr object)->bool {
		locked = false;
		return true;
		});


	startGame(room1);
}