#include <iostream>
#include <cstring>
#include <vector>
#include "helper.hpp"

using namespace std;

Player::Player(const string& name, float x, float y)
    : name(name), position(x, y), velocity(0, 0), jumpStrength(10.0f), score(0) {}

void Player::jump(float power) {
    velocity.setY(-power * jumpStrength);
}

void Player::moveLeft(float speed) {
    velocity.setX(-speed);
}

void Player::moveRight(float speed) {
    velocity.setX(speed);
}

void Player::update(float deltaTime) {
    position.add(Vector2D<float>(velocity.getX() * deltaTime, velocity.getY() * deltaTime));
    velocity.setY(velocity.getY() + 9.8f * deltaTime);
}

void Player::resetPosition() {
    position = Vector2D<float>(0.0f, 0.0f);
}

Vector2D<float> Player::getPosition() const {
    return position;
}

int Player::getScore() const {
    return score;
}

void Player::incrementScore() {
    score++;
}

std::string Player::getName() const {
    return name;
}


Ball::Ball(float x, float y, float radius)
    : position(x, y), velocity(0, 0), radius(radius) {}

void Ball::update(float deltaTime) {
    position.add(Vector2D<float>(velocity.getX() * deltaTime, velocity.getY() * deltaTime));
    velocity.setY(velocity.getY() + 9.8f * deltaTime);
}

void Ball::reset() {
    position = Vector2D<float>(0, 0);
    velocity = Vector2D<float>(0, 0);
}

void Ball::bounce(bool vertical) {
    if (vertical) {
        velocity.setY(-velocity.getY());
    } else {
        velocity.setX(-velocity.getX());
    }
}

Vector2D<float> Ball::getPosition() const {
    return position;
}

Vector2D<float> Ball::getVelocity() const {
    return velocity;
}

void Ball::setVelocity(const Vector2D<float>& vel) {
    velocity = vel;
}


Net::Net(float x, float height) : xPosition(x), height(height) {}

float Net::getX() const {
    return xPosition;
}

float Net::getHeight() const {
    return height;
}