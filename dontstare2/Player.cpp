#include "Player.h"

Player::Player(vec2 _position) : position(_position) {

}

vec2 Player::getPosition() {
	return position;
}

void Player::changePosition(vec2 change) {
	position = position + change;
}