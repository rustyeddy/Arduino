class Display {
private:
    int color_text;
    int color_background;
    int x, y;

public:
    Display() {
	color_text = BLUE;
	color_background = WHITE;
	M5.Lcd.fillScreen(color_background);
    }

    void background(int color) {
	M5.Lcd.fillScreen(color);
    }
};
