#include <iostream>
#include <algoviz/SVG.hpp>
using namespace std;

#define BREITE 50
#define SPIELFELD_HOEHE 400

class Barriere {
    protected:
    
    Rect *lowerComponent;
    Rect *upperComponent;
    int upperHeight;
    int lowerHeight;
    int bottleneckHeight;
    int xCoord;
    
    public:
    
    Barriere (int upperHeight, int bottleneckHeight, int xCoord, SVG &spielfeld) {
        this->upperHeight = upperHeight;
        this->bottleneckHeight = bottleneckHeight;
        this->lowerHeight = SPIELFELD_HOEHE - upperHeight - bottleneckHeight;
        this->xCoord = xCoord;
        
        upperComponent = new Rect(xCoord, 0, BREITE, upperHeight, &spielfeld);
        lowerComponent = new Rect(xCoord, upperHeight + bottleneckHeight, BREITE, lowerHeight, &spielfeld);
    }
    
    int getUpperHeight () {
        return upperHeight;
    }
    
    int getLowerHeight () {
        return lowerHeight;
    }
    
    int getBottleneckHeight () {
        return bottleneckHeight;
    }
    
    int getXCoord () {
        return xCoord;
    }
    
    void setXCoord (int newXCoord) {
        this->xCoord = newXCoord;
        upperComponent->moveTo(xCoord, 0);
        lowerComponent->moveTo(xCoord, upperHeight + bottleneckHeight);
    }  
    
    void setFill (int r, int g, int b, float a) {
        lowerComponent->setFill(r, g, b, a);
        upperComponent->setFill(r, g, b, a);
    }
    
    void setColor (int r, int g, int b, float a) {
        upperComponent->setColor(r, g, b, a);
        lowerComponent->setColor(r, g, b, a);
    }
    
    /* Tut nichts, wird von der Subklasse verändert. */
    virtual void update () {
    }
};

class DynamischeBarriere : public Barriere {
    private:
    int bottleneckMoveSpeed;
    bool moveBottleneckUp;
    
    public:
    DynamischeBarriere (int bottleneckHeight, int xCoord, SVG &spielfeld)
    : Barriere (0, bottleneckHeight, xCoord, spielfeld) {
        // Wie schnell soll sich die Öffnung pro Iteration verschieben?
        bottleneckMoveSpeed = (rand() % 10) + 2;
        moveBottleneckUp = false;
    }
    
    void update () override {
        // Muss sich die Öffnung hoch oder runter bewegen?
        if (upperHeight - bottleneckMoveSpeed <= 0) {
            moveBottleneckUp = false;
        } else if (upperHeight + bottleneckHeight + bottleneckMoveSpeed >= SPIELFELD_HOEHE) {
            moveBottleneckUp = true;
        }
        
        if (moveBottleneckUp) {
            upperHeight -= bottleneckMoveSpeed;
            lowerHeight += bottleneckMoveSpeed;
        } else {
            upperHeight += bottleneckMoveSpeed;
            lowerHeight -= bottleneckMoveSpeed;
        }
        upperComponent->setHeight(upperHeight);
        lowerComponent->moveTo(xCoord, upperHeight + bottleneckHeight);
        lowerComponent->setHeight(lowerHeight);
    }
};