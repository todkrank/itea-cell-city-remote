#include <iostream>
#include <vector>

int main(void)
{
 unsigned long n,m,r,c1,c2,c;//n - rows, m - columns, k - railways
 unsigned long long lanterns=0;
 unsigned k;
 std::cin>>n>>m>>k;
 std::vector<std::vector<char>*>cityRows;
 for(unsigned i=0;i<n;i++){
  cityRows.push_back(new std::vector<char>);//!!which size? is there a way to initialize m elements as 0 in this line?🌈
  //cityRows.back()->reserve(m);
  cityRows.back()->assign(m,1);
 }

 for(unsigned i=0;i<k;i++){
  std::cin>>r>>c1>>c2;
  if(c1>c2){
   c=c1; c1=c2; c2=c;
  }
  for(unsigned j=c1;j<=c2;j++){
   //cellPtr=cityRows.at(r-1)+j-1;
   cityRows.at(r-1)->at(j-1)=0;
  }
 }

 for(unsigned i=0;i<n;i++){
  for(unsigned j=0;j<m;j++){
   lanterns+=static_cast<unsigned>(cityRows.at(i)->at(j));
  }
 }
 std::cout<<lanterns<<std::endl;

 for(unsigned i=0;i<m;i++){
  delete cityRows.at(i);
 }

 return EXIT_SUCCESS;
}
