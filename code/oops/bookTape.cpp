#include<iostream>
#include <string>
using namespace std;

class publication
{
        protected :
                string title;
                float price;
        public :
                void getdata();
                void putdata();
                publication()
                {
                        title = " ";    price = 0;
                }
};

class book : public publication
{
        private :
                int pagecount;
        public :
                void get_book_data();
                void put_book_data();
                book()
                {
                        pagecount = 0;
                }
};

class tape : public publication
{
        private :
                float playtime;
        public :
                void get_tape_data();
                void put_tape_data();
                tape()
                {
                        playtime = 0;
                 }
};

void book :: get_book_data()
{       
        cout<<"enter title, price, number of pages of book : ";
        try
        {
            getline(cin>>ws , title);
            cout<<"\n";
            cin>>price>>pagecount;
            if(price<0)
            {
                throw(2);
            }
        }
        catch(int x)
        {
                cout<<"price not valid ";
                price = 0;
                title = " ";
                pagecount = 0;
        }  
}

void book :: put_book_data()
{
        cout<<" title , price , pagecount is : " <<title<<" , " <<price<<" , "<<pagecount<<endl;
}

void tape :: get_tape_data()
{
        
        cout<<"enter title,  play time : ";
        try
        {
            getline(cin>>ws , title);
            cout<<"\n";
            cin>>playtime;
            if(playtime<0)
            {
                throw(2);
            }
        }
        catch(int x)
        {
                cout<<"playtime not valid "<<endl;
                price = 0;
                title = " ";
                playtime = 0;
        }    
        
}

void tape :: put_tape_data()
{
        cout<<"playtime , title is : "<<playtime<<", "<<title<<endl;
}
int main()
{
        publication p;
        book b;
        tape t;
        b.get_book_data();
        b.put_book_data();
        t.get_tape_data();
        t.put_tape_data();
        return 0;
}





