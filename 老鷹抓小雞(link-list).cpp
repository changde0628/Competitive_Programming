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
