/*  Hasna Karimah
    Tugas Praktikum Analisis Algoritma - Worksheet 1
    Stable Marriage Problem
    ===============================*/

#include <iostream>
using namespace std;

int findIndex(string name){
    int resultIndex;
    if (name == "Victor" || name == "Amy")
        resultIndex = 0;
    else if (name == "Wyatt" || name == "Bertha")
        resultIndex = 1;
    else if (name == "Xavier" || name == "Clare")
        resultIndex = 2;
    else if (name == "Yancey" || name == "Diane")
        resultIndex = 3;
    else
        resultIndex = 4;

    return resultIndex;
}

int main()
{
    string men[5][2] = {
        {"Victor", "free"},
        {"Wyatt", "free"},
        {"Xavier", "free"},
        {"Yancey", "free"},
        {"Zeus", "free"},
    };
    string menPreference[5][5] = {
        {"Bertha", "Amy", "Diane", "Erika", "Clare" },  // Victor
        {"Diane", "Bertha", "Amy", "Clare", "Erika" },  // Wyatt
        {"Bertha", "Erika", "Clare", "Diane", "Amy" },  // Xavier
        {"Amy", "Diane", "Clare", "Bertha", "Erika" },  // Yancey
        {"Bertha", "Diane", "Amy", "Erika", "Clare" }   // Zeus
    };
    string women[5][2] = {
        {"Amy", "free"},
        {"Bertha", "free"},
        {"Clare", "free"},
        {"Diane", "free"},
        {"Erika", "free"},
    };
    string womenPreference[5][5] = {
        {"Zeus", "Victor", "Wyatt", "Yancey", "Xavier" },  // Amy
        {"Xavier", "Wyatt", "Yancey", "Victor", "Zeus" },  // Bertha
        {"Wyatt", "Xavier", "Yancey", "Zeus", "Victor" },  // Clare
        {"Victor", "Zeus", "Yancey", "Xavier", "Wyatt" },  // Diane
        {"Yancey", "Wyatt", "Zeus", "Xavier", "Victor" }   // Erika
    };
    string engaged[5][2] = {
        { "Amy", "?"},
        { "Bertha", "?"},
        { "Clare", "?"},
        { "Diane", "?"},
        { "Erika", "?"}
    };

    
    bool isSomeoneFree = true;
    int tries = 0;

    for (int i=0; i<5; i++){

        for (int j=0; j<5; j++){

            
            if (men[i][1] == "free"){
                
                if (women[ findIndex(menPreference[i][j]) ][1] == "free" ){
                    
                    men[i][1] = "engaged";
                    women[ findIndex(menPreference[i][j]) ][1] = "engaged";
                    engaged[ findIndex(menPreference[i][j]) ][1] = men[i][0];
                    cout<<engaged[ findIndex(menPreference[i][j]) ][1] <<" with "
                        <<engaged[ findIndex(menPreference[i][j]) ][0]
                        <<" engaged!" <<endl;
                    isSomeoneFree = false;
                    
                    break;
                }

                
                else {
                    
                    for (int k=0; k<5; k++){

                        if ( womenPreference[ findIndex(menPreference[i][j]) ][k] ==
                            engaged[ findIndex(menPreference[i][j]) ][1] )
                            break;

                        if ( womenPreference[ findIndex(menPreference[i][j]) ][k] == men[i][0]
                            && k < 5 ){
                            
                            cout<<engaged[ findIndex(menPreference[i][j]) ][1] <<" with "
                                <<engaged[ findIndex(menPreference[i][j]) ][0]
                                <<" break apart! then ";

                            men[ findIndex(engaged[ findIndex(menPreference[i][j]) ][1]) ][1] = "free";

                            
                            men[i][1] = "engaged";
                            women[ findIndex(menPreference[i][j]) ][1] = "engaged";
                            engaged[ findIndex(menPreference[i][j]) ][1] = men[i][0];

                            cout<<engaged[ findIndex(menPreference[i][j]) ][1] <<" with "
                                <<engaged[ findIndex(menPreference[i][j]) ][0]
                                <<" engaged!" <<endl;
                            isSomeoneFree = true;
                        }
                    }
                }
            }
            else
                break;
        }
        
        Tries++;

        if (isSomeoneFree == true && i == 5 - 1 )
            i = -1; 
    }

    if (isSomeoneFree == false){
        cout<<endl <<endl
            <<"Stable couple are : "<<endl<<endl;
        for(int i=0; i<5; i++){
            cout<<engaged[i][1] <<" engaged with "
                <<engaged[i][0] <<endl;
        }
    }

    return 0; 
}
