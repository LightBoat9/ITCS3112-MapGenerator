#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

class Room{

    protected:
    int x; int y;
    int width; int height;
    bool** room;

    public:

    Room()
    {
        width = height = x = y = 0;
        room = new bool[0];
    }




    void setXCord(int xCor)
    {
        x = xCor;
    }
    int getXCord()
    {
        return x;
    }
    void setYCord(int yCor)
    {
        y = yCor;
    }
    int getYCord()
    {
        return y;
    }

    void setRoom(int width, int height)
    {
        this->width = width; this->height = height;
    }
    bool** getRoom()
    {
        return room;
    }
};

#endif // ROOM_H_INCLUDED
