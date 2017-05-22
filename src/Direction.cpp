
void Direction_convert(int Direction, float &dx, float &dy, float speed) {
	switch (Direction) {
	case 0:
		dx = speed;
		dy = 0;
		break;

	case 1:
		dx = -speed;
		dy = 0;
		break;

	case 2:
		dy = speed;
		dx = 0;
		break;

	case 3:
		dy = -speed;
		dx = 0;
		break;

	case 4:
		dx = -speed;
		dy = -speed;
		break;

	case 5:
		dx = speed;
		dy = -speed;
		break;

	case 6:
		dx = speed;
		dy = speed;
		break;

	case 7:
		dx = -speed;
		dy = speed;
		break;

	case 8:
		dx = 0;
		dy = 0;
		break;
	}
}