#include <iostream>
#include <map>
#include<iomanip>
using namespace std;
int main()
{
    map<string, long> populationMap;

    string states[]={"Uttar Pradesh","Maharashtra","Bihar","West Bengal","Andhra Pradesh","Madhya Pradesh","Tamil Nadu","Rajasthan","Karnataka","Punjab",
    "Gujarat","Orissa","Kerala","Jharkhand","Assam","Chhattisgarh","Haryana",
    "Uttarakhand","Himachal Pradesh","Tripura","Meghalaya","Manipur", "Goa",
    "Nagaland", "Arunachal Pradesh","Mizoram","Delhi"},state;

    long populations[]={199812341,112374333,104099452,91276115, 72147030,
    68548437,61095297,60439692,41974218,33406061,32988134,31205576,
    27743338,25545198,25351462,10086292,6864602,3673917, 2966889,2855794,
    1978502,1458545,1383727,1097206,16787941,12541302},population;

    for(int i=0;i<26;i++)
        populationMap.insert(pair<string, long>(states[i],populations[i]));

    int cho; char ch;
    map<string, long>::iterator iter = populationMap.begin();
    do
    {
        cout<<"\n\t\t Map Menus"<<endl;
        cout<<"\n\t 1. Display all States Population"<<"\n\t 2. Find Particular State Population"<<"\n\t 3. Update Population"<<"\n\t 4. Size of Population Map"<<"\n\t 5. Add another State Population"<<"\n\t 6. Exit"
        <<"\n\t Enter your choice:";

        cin>>cho;
        switch(cho){
                case 1: cout<<"\n\t"<<left<<setw(30)<<"State " <<setw(20) <<"Population"<<endl;
                    for (iter = populationMap.begin(); iter != populationMap.end(); ++iter)
                        cout <<"\t"<<left<<setw(30)<<iter->first <<setw(20) << iter->second <<endl;

                    break;

                case 2: cout<<"\n\t Enter the State Name:";
                    fflush(stdin);
                    getline(cin,state);
                    iter = populationMap.find(state);
                    if( iter != populationMap.end() )
                        cout <<"\n\t "<<state <<"'s populations is "<< iter->second <<endl;
                    else
                        cout << "\n\t Key is not in populationMap" <<endl;

                    break;

                case 3: cout<<"\n\t Enter the State Name:";
                    fflush(stdin);
                    getline(cin,state);

                    cout<<"\n\t Enter Updated Population Count:";
                    cin>>population;
                    populationMap[state]=population;

                    break;
                case 4: cout << "Size of populationMap: " << populationMap.size() ;
                    break;

                case 5: cout<<"\n\t Enter the State Name:";
                    fflush(stdin);
                    getline(cin,state);

                    cout<<"\n\t Enter Population Count:";
                    cin>>population;
                    populationMap.insert(pair<string, long>(state,population));

                    break;
                case 6: exit(0);

                default:cout<<"\n\t Enter choice inbetween 1 to 5 only.";
                    break;
        }

        cout<<"\n\t Do you want to continue(y/n):";
        fflush(stdin);
        cin>>ch;
        
    }while(ch=='y'||ch=='Y');

    return 0;
}