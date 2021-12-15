#include <iostream>

#define DAY 1440

int hm2min(int h, int m){
  return h*60+m;
}

int main(){
  int N;
  std::cin >> N;
  int starts[N], ends[N];
  int min = DAY*2, max = 0;

  for(int i=0;i<N;++i){
    int his, mis, hie, mie;
    std::cin >> his >> mis >> hie >> mie;

    starts[i] = hm2min(his, mis);
    ends[i] = hm2min(hie, mie);

    if(ends[i] < starts[i]){
      ends[i] += DAY;
    }
    if(starts[i] > max){
      max = starts[i];
    }
    if(ends[i] < min){
      min = ends[i];
    }
  }

  for(int i = 0; i < N; ++i){
    int curr_index = i;
    for(int j = 0; j < N; ++j){
      if(curr_index == j)
        continue;
      bool overlap = starts[i] < ends[j] && starts[j] < ends[i];
      if(!overlap){
          std::cout << "NE" << std::endl;
          return 0;
      }
    }
  }

  printf("TAIP\n");
  printf("%d %d %d %d\n",(max%DAY)/60, (max%DAY)%60, (min%DAY)/60, (min%DAY)%60);
  return 0;
} 