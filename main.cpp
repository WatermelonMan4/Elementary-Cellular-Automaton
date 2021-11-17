#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <iostream>

int rule_dec;
int rule_bin[8] = {0,0,0,0,0,0,0,0};

//Function converting decimal number for binary
void convNum (int k)
{
    if (k%2 == 1) rule_bin[7] = 1;
    k = k/2;
    if (k%2 == 1) rule_bin[6] = 1;
    k = k/2;
    if (k%2 == 1) rule_bin[5] = 1;
    k = k/2;
    if (k%2 == 1) rule_bin[4] = 1;
    k = k/2;
    if (k%2 == 1) rule_bin[3] = 1;
    k = k/2;
    if (k%2 == 1) rule_bin[2] = 1;
    k = k/2;
    if (k%2 == 1) rule_bin[1] = 1;
    k = k/2;
    if (k%2 == 1) rule_bin[0] = 1;
}

int main()
{
    //Variables
    float posX=0, posY=0;
    int random_num, width, height, iterations, counter=0;

    //Create the main window
    width=800;
    height=600;

    std::cout<<"Give any decimal number from 1 to 100: ";
    std::cin>>rule_dec;
    sf::RenderWindow app(sf::VideoMode(width, height, 32), "Elementary Cellural Automaton");
	
    int tab1[width], tab2[width];

	//Filing empty tables with zeros
    for (int i=0;i<width;i++)
    {
        tab1[i] = 0;
        tab2[i] = 0;
    }

	//Starting point for pseudorandom number generator
    srand(time(NULL));

    sf::RectangleShape rectangle(sf::Vector2f(1,1));

    //rule_dec = 18;
    iterations = 598;
    convNum(rule_dec);

    app.clear();

    //Top start
    tab1[width/2]=1;
    posX=width/2;
    rectangle.setPosition(posX,posY);
    rectangle.setFillColor(sf::Color::Green);
    app.draw(rectangle);
	
    posX=0;
    posY=1;
    /*
    //random start
    for (int i=0; i<width; i++)
    {
        random_num = ((rand() % width) + 0);
        tab1[random_num] = 1;
    }
    for (int i=0;i<width;i++)
        {
            rectangle.setPosition(posX,posY);
            if(tab1[i]==1)
            {
                rectangle.setFillColor(sf::Color::Green);
                app.draw(rectangle);

            }else if (tab1[i]==0)
            {
                rectangle.setFillColor(sf::Color::Black);
                app.draw(rectangle);
            }
            app.display();
            posX+=1;
            if(posX==width)
            {
                posX=0;
                posY=1;
                break;
            }
        }*/
		
	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
            /*if (event.type == sf::Event::TextEntered)
                if (event.text.unicode < 128)
                {
                    std::cout<<"Tekst: "<<static_cast<char>(event.text.unicode)<<std::endl;
                }*/
        }

        for(int i=0;i<=iterations;i++)
        {
            if (counter==iterations) break;
            for (int j = 1; j<width-1; j++)
            {
            if (tab1[j-1]==0 && tab1[j]==0 && tab1[j+1]==0) tab2[j] = rule_bin[7];
            else if (tab1[j-1]==0 && tab1[j]==0 && tab1[j+1]==1) tab2[j] = rule_bin[6];
            else if (tab1[j-1]==0 && tab1[j]==1 && tab1[j+1]==0) tab2[j] = rule_bin[5];
            else if (tab1[j-1]==0 && tab1[j]==1 && tab1[j+1]==1) tab2[j] = rule_bin[4];
            else if (tab1[j-1]==1 && tab1[j]==0 && tab1[j+1]==0) tab2[j] = rule_bin[3];
            else if (tab1[j-1]==1 && tab1[j]==0 && tab1[j+1]==1) tab2[j] = rule_bin[2];
            else if (tab1[j-1]==1 && tab1[j]==1 && tab1[j+1]==0) tab2[j] = rule_bin[1];
            else if (tab1[j-1]==1 && tab1[j]==1 && tab1[j+1]==1) tab2[j] = rule_bin[0];
            }

                for (int i=0;i<width;i++)
                {
                    rectangle.setPosition(posX,posY);
                    if(tab2[i]==1)
                    {
                    rectangle.setFillColor(sf::Color::Green);
                    app.draw(rectangle);

                }else if (tab2[i]==0)
                {
                    rectangle.setFillColor(sf::Color::Black);
                    app.draw(rectangle);
                }
				
                posX+=1;
                if(posX==width)
                {
                    posX=0;
                    posY+=1;
                }
                tab1[i] = tab2[i];
                tab2[i] = 0;
                }
                counter++;
        }
        app.display();
    }

    return 0;
}
