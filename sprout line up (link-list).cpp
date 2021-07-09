#include <iostream>
#include <string>
struct Player {
	int id;
	struct Player *nxt;
};

void createChickenList(int n);		// 建立所有的玩家資料
void rotateChickenList();		// 換一位母雞
void attack(int id);			// 老鷹試圖攻擊編號id的雞
void print();				// 印出當前狀態

Player *hen = nullptr;
Player *eagle = nullptr;
Player *tail = nullptr;
int len;

int main()
{
	int m, n;
	std::cin >> n;
	createChickenList(n);
	len = n - 1;

	std::cin >> m;
	while(m--){
		std::string inst;
		int id;

		std::cin >> inst;
		if(inst == "attack"){
			std::cin >> id;
			attack(id);
		}else if(inst == "rotate"){
			rotateChickenList();
		}
		print();
	}

	// delete list
	Player *nxt;
	while(hen){
		nxt = hen->nxt;
		delete hen;
		hen = nxt;
	}
	delete eagle;

	return 0;
}

void createChickenList(int n)
{
    eagle = new Player;
    eagle ->id = 1;
    hen = new Player;
    hen ->id = 2;
    tail = hen;
    for(int i=3;i<=n;i++)
    {
        Player *tmp = new Player;
        tail->nxt = tmp;
        tmp -> id = i;
        tail = tmp;
    }
    tail ->nxt = nullptr;
}

void rotateChickenList()
{
    Player *tmp = hen;
    if(hen->nxt!=nullptr)
    {
        hen = hen->nxt;
        tail ->nxt = tmp;
        tail = tmp;
        tail -> nxt = nullptr;
    }
}
void attack(int id)
{
    int counter = 1;
    double protect = len/3.0;
    if(protect<1) protect = 1;
    Player *tmp = hen;
    Player *fronttmp = hen ;
    while(tmp->id!=id)
    {
        fronttmp = tmp;
        tmp = tmp->nxt;
        counter++;
    }
    if(counter>protect)
    {
        Player *save = new Player;
        save = eagle;
        eagle = tmp;
        save->nxt = tmp ->nxt;
        tmp = save;
        fronttmp ->nxt = tmp;
        if(save->nxt==nullptr)
        {
            tail = save;
        }
    }
}

void print()
{
    Player *current = hen;
    std::cout<<eagle->id<<std::endl;
    while(1)
    {
        if(current->nxt!=nullptr)
        {
            std::cout<<current->id<<" ";
            current = current->nxt;
        }
        else
        {
            std::cout<<current->id;
            break;
        }
    }
    std::cout<<std::endl;
}
