namespace events{
	/**
	* A generic structure to encapsulate SDL events. This will be used to pass information to
	* the main game loop about input, letting the game loop control what happens with said
	* input.
	*/
	struct gameEvent{
		// Determines if any events have occurred.
		bool hasEvents;
		// Determines if the game has been quit.
		bool hasQuit;
		// Which key on the keyboard was pressed, if any.
		char keyPressed;
		// Determines if the key is down.
		bool keyDown;
		// Determines if the pressed key has been released. May not be needed presently.
		bool keyReleased;
		// The x position of the cursor on the screen.
		int mouseX;
		// The y position of the cursor on the screen.
		int mouseY;
		// The ID of the mouse button that was pressed, if any.
		int button;
		// Determines if the button is down.
		bool buttonDown;
		// Determines if the pressed button has been released. May not be needed presently.
		bool buttonReleased;

		gameEvent(){
			hasEvents = false;
			hasQuit = false;
			keyPressed = NULL;
			keyDown = false;
			keyReleased = false;
			mouseX = 0;
			mouseY = 0;
			button = 0;
			buttonDown = false;
			buttonReleased = false;
		};

		gameEvent& operator=(const gameEvent& otherEvent){
			this->hasEvents = otherEvent.hasEvents;
			this->hasQuit = otherEvent.hasQuit;
			this->keyPressed = otherEvent.keyPressed;
			this->keyDown = otherEvent.keyDown;
			this->keyReleased = otherEvent.keyReleased;
			this->mouseX = otherEvent.mouseX;
			this->mouseY = otherEvent.mouseY;
			this->button = otherEvent.button;
			this->buttonDown = otherEvent.buttonDown;
			this->buttonReleased = otherEvent.buttonReleased;

			return *this;
		};
	};
}