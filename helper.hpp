#ifndef HELPER_HPP
#define HELPER_HPP

#include <string>

using namespace std;

template<typename T>
class Vector2D {
private:
    T x, y;

public:
    Vector2D(T x = 0, T y = 0) : x(x), y(y) {}

    T getX() const { return x; }
    T getY() const { return y; }
    void setX(T val) { x = val; }
    void setY(T val) { y = val; }

    void add(const Vector2D<T>& other) {
        x += other.x;
        y += other.y;
    }
};


class Player {
private:
    Vector2D<float> position;
    Vector2D<float> velocity;
    float jumpStrength;
    int score;
    string name;

public:
    Player(const string& name, float x, float y);

    void jump(float power);
    void moveLeft(float speed);
    void moveRight(float speed);
    void update(float deltaTime);
    void resetPosition();

    Vector2D<float> getPosition() const;
    int getScore() const;
    void incrementScore();
    string getName() const;
};


class Ball {
private:
    Vector2D<float> position;
    Vector2D<float> velocity;
    float radius;

public:
    Ball(float x, float y, float radius);

    void update(float deltaTime);
    void reset();
    void bounce(bool vertical = true);
    Vector2D<float> getPosition() const;
    Vector2D<float> getVelocity() const;
    void setVelocity(const Vector2D<float>& vel);
};


class Net {
private:
    float xPosition;
    float height;

public:
    Net(float x, float height);
    float getX() const;
    float getHeight() const;
};

#endif 