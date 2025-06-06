#include <iostream>
#include <vector>
using namespace std;

class pgfaultfifo{
    public:
    
    int frameindx=0;//staring frames index 
    int pagecounter=0; //increment
    int pagesindx=0;//pages indexing
    int framesize=3;
    vector<int> pages={0,1,2,0,3,4,5,1,2,3,5,0};
    vector<int>frames={};
    void hit(){
       for(frameindx;frameindx<framesize;frameindx++){
            frames.insert(frames.end(),pages.at(pagesindx));
           
            cout<<pagesindx;
             pagesindx++;
           
          
            for(pagesindx;pages.size();pagesindx++){
                if (pages.at(pagesindx)==frames.at(0))
                {
                    cout<<"hit";
                }
                
            
        
            }

            
        }}
    //cout<<pages.at(3)<<endl;
    //cout<<frames.size(); 
    //  for(int frameindx;frameindx<frames.size();frameindx++){              
    //    
    //         pagesindx++;
    //     }
    //      else{
          
    //         frames.insert(frames.begin(),pages.at(0));
    //         //frames.at((frameindx+1)%frames.size())=pages.at(pagesindx);
    //         pagecounter++; }
        
        

    //  }
     for(int i=0;i<frames.size();i++){
         cout<<endl<<frames.at(i);
         }
        


      
        
   
}};

int main(){
    pgfaultfifo f;
   
    f.hit();
      
}