#pragma once

enum AnimationType {
	HORIZONTAL = '_',
	LEFT = '\\',
	VERTICAL = '|',
	RIGHT = '/'
};

enum AnimationTypeIdx {
	HORIZONTAL_IDX,
	LEFT_IDX,
	VERTICAL_IDX,
	RIGHT_IDX,
	ANIMATION_COUNT
};

class Stick {
public:
	int getPosition() const {
		return _position;
	}

	char nextAnimation() const {
		++_animationFrameCount;

		if (ANIMATION_COUNT == _animationFrameCount) {
			_animationFrameCount = 0;
		}

		switch (_animationFrameCount) {
		case HORIZONTAL_IDX:
			_animation = HORIZONTAL;
			break;
		case LEFT_IDX:
			_animation = LEFT;
			break;
		case VERTICAL_IDX:
			_animation = VERTICAL;
			++_position;
			break;
		case RIGHT_IDX:
			_animation = RIGHT;
			break;
		default:
			break;
		}

		return _animation;
	}
private:
	mutable int _position = 0;
	mutable char _animation = ' ';
	mutable int _animationFrameCount = 0;
};
