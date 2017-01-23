#include <fstream>
using namespace std;

constexpr long dots = 100;

long dots_vertically = 32 + 10;
long dots_horizontally = 50 + 10;
	
long border_top	= 10 * dots;
long border_bottom	= 6 * dots;
long border_left	= 6 * dots;
long border_right	= 6 * dots;


long label_height = 8 * dots;
	
long height(){
		return border_top + 100 * (dots_vertically + 1) + label_height + border_bottom;		
	}
long width(){
		return border_left + 100*(dots_horizontally + 1) + border_right;
	}
	
int main(){
    fstream f;
    f.open("output.svg", ios::out);
    f << "<?xml version=\"1.0\" standalone=\"no\"?> <svg width=\"" << width() << "\" height=\"" << height() << "\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">";
	
	// draw rahmen####
	f << "<path d=\"M " << border_left << " " << border_top + (dots_vertically+1) * dots << " V "
		<< border_top << " h " << dots* (dots_horizontally+1) << " v " << (dots_vertically+1) * dots
		<< " H " << border_left << " v " << label_height << " h " << dots* (dots_horizontally+1) <<
		" v " << -label_height << " z \" stroke=\"black\" stroke-width=\"20\" fill=\"none\" />";
	
	// draw platine dots:
	for (long x = border_left + 100; x <= border_left + dots_horizontally * dots; x+=100){
		for (long y= border_top + 100; y <= border_top + dots_vertically * dots; y +=100){
			f << "<circle cx=\"" << x << "\" cy=\"" << y <<"\" r=\"16\" stroke=\"black\" stroke-width=\"4\" fill=\"grey\" />";
		}
	}
	
	f << "</svg>";
	f.close();
}
