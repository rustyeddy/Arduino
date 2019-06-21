class Pin {
protected:
    int _pin = -1;
    int _mode = -1;

public:
    Pin(int p) { _pin = p; }

    void mode(int m) {
	if (m == OUTPUT || m == INPUT) {
	    m = _mode;
	}
	pinMode(_pin, m);
    }

    double analogRead() {
	return ::analogRead(_pin);
    }

    int digitalRead() {
	return ::digitalRead(_pin);
    }
};

class OnOff {
    
}

