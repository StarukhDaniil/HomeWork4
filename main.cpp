#include <iostream>
#include <vector>

struct GameActor {
	std::string name;

	GameActor(std::string name = "Default name") : name(name) {}

	void draw() {
		std::cout << name << std::endl;
	}
};

std::vector<GameActor*> actors;

GameActor* duplicateGameActor(const size_t index) {
	if (index == 0) {
		std::cout << "NULL" << std::endl;
	}
	if (index < actors.size() && index >= 0) {
		return new GameActor(*actors[index]);
	}
	else {
		return new GameActor();
	}
}

GameActor* duplicateGameActor(const GameActor* actor) {
	if (actor == nullptr) {
		std::cout << "nullptr" << std::endl;
		return new GameActor();
	}
	else {
		return new GameActor(*actor);
	}
}

void clean() {
	for (GameActor* actor : actors) {
		delete actor;
		actor = nullptr;
	}
}

void showActors() {
	for (int i = 0; i < actors.size(); i++) {
		actors[i]->draw();
	}
}

int main() {
	actors.emplace_back(duplicateGameActor(nullptr));
	actors.emplace_back(duplicateGameActor(static_cast<size_t>(NULL)));
	actors.emplace_back(duplicateGameActor(new GameActor("Alex")));



	showActors();
	clean();
	return 0;
}