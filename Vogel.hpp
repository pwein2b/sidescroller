#include <iostream>
#include <algoviz/SVG.hpp>
using namespace std;

class Vogel {

        private:
        Image figure;
        int xPosition;
        int yPosition;
        bool dead = true;
        
        public:
        Vogel(SVG &spielfeld) { 
            this->xPosition = 200;
            this->yPosition = 50;
            figure = Image("https://miro.medium.com/max/724/1*ey7wIxpYa7Er7nRHhwyirQ.png", xPosition, yPosition, 40, 40, &spielfeld);
        }
    
         /**************
          ** Methods **
          **************/
    
        // get Y-Coordinate
        int getYKoordinate(){
            return figure.getY();         
        }
    
        // rocket dies
        void vogelDead(){
            int r;
            while (dead == true){
                figure.moveTo(figure.getX(),figure.getY() + 2);
                figure.moveTo(figure.getX() + 1,figure.getY());
                figure.rotateTo(0 + r);
                r += 2;
                if (figure.getY() > 450){
                    dead = false;
                    figure.hide();
                }
            }
        }
    
        // move along y-axis. X-axis constantly 200!
        void move(int y){
            figure.moveTo(200, y);
        }
        
        // change rotation
        void rotate(int grad){
            figure.rotateTo(grad);
        }
};