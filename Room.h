#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

class Room{

    protected:
    int X; int Y;
    int WIDTH; int HEIGHT;
    bool** ROOM;

    public:

    Room()
    {
       WIDTH = HEIGHT = X = Y = 0;
        ROOM = new bool[0];
    }




    void setXCord(int xCor)
    {
        X = xCor;
    }
    int getXCord()
    {
        return X;
    }
    void setYCord(int yCor)
    {
        Y = yCor;
    }
    int getYCord()
    {
        return Y;
    }

    void setRoom(int width, int height)
    {
        this->WIDTH = width; this->HEIGHT = height;
    }
    bool** getRoom()
    {
        return ROOM;
    }
};

#endif // ROOM_H_INCLUDED
