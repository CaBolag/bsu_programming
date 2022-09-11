#include "headers.h"
vector<FlowerBed> GreenHouse::ReadData(string filename) {
  vector<FlowerBed> data;
  std::ifstream fin(filename);
  if (!fin.is_open()) {
    std::cout << "Error!\n";
    return data;
  }
  string string_data;
  FlowerBed flower_bed;
  while (!fin.eof()) {
    getline(fin,string_data);
    istringstream string_stream(string_data);
    string_stream >> flower_bed;
    data.push_back(flower_bed);
  }
  return data;
}

void GreenHouse::PrintData(vector<FlowerBed> data,string filename) {
    std::ofstream out (filename);
    std::copy(data.begin(),data.end(),std::ostream_iterator<FlowerBed>(out,"\n"));
}

void GreenHouse::SortByShape(vector<FlowerBed> data) {
  sort(data.begin(),data.end(),CompareByShape());
}


multimap<Shape,FlowerBed> GreenHouse::MoveToContainer(vector<FlowerBed> data) {
  multimap<Shape, FlowerBed> container;
  for (const FlowerBed& flower_bed : data) {
    container.insert(make_pair(flower_bed.GetShape(),flower_bed));
  }
  return container;
}

void GreenHouse::PrintVarietyOfFlowers(vector<FlowerBed> data,string filename) {
  ofstream out(filename,ios::app);
  set<string> flowers;
  for(int i=0;i<data.size();++i){
    vector<string> one_fbed_flowers=data[i].GetFlowers();
    for(int j=0;j<one_fbed_flowers.size();++j){
      flowers.insert(one_fbed_flowers[j]);
    }
  }
  out<<"Variety of flowers: ";
  std::copy(flowers.begin(),flowers.end(),std::ostream_iterator<string>(out," "));
  out<<"\n";
}

void GreenHouse::PrintFlowersByNumber(vector<FlowerBed> data,string filename,int bed_number) {
  ofstream out(filename,ios::app);
  auto iterator=std::find_if(data.begin(),data.end(),
                              [bed_number](const FlowerBed& flower_bed){return bed_number==flower_bed.GetNumber();});
  out<<"Flowers in the flower bed number "<<bed_number<<": ";
  vector<string> flowers=iterator->GetFlowers();
  std::copy(flowers.begin(),flowers.end(),std::ostream_iterator<string>(out," "));
  out<<"\n";
}

vector<FlowerBed> GreenHouse::FbedWithMaxFlowers(vector<FlowerBed> data) {
  vector<FlowerBed> result;
  multimap<int, FlowerBed> amount_of_flowers;
  for (int i = 0; i < data.size(); i++) {
    amount_of_flowers.insert(make_pair(data[i].GetFlowers().size(), data[i]));
  }
  int max_size = amount_of_flowers.rbegin()->first;
  pair range = amount_of_flowers.equal_range(max_size);
  for (auto i = range.first; i != range.second; ++i) {
    result.push_back(i->second);
  }
  return result;
}

vector<FlowerBed> GreenHouse::TheSameFlowers(vector<FlowerBed> data) {
  vector<FlowerBed> the_same_flowers;
  for (int i = 0; i < data.size(); ++i) {
    vector<string> flowers = data[i].GetFlowers();
    int flowers_amount=count(flowers.begin(), flowers.end(), flowers[0]);
    if (flowers_amount == flowers.size()) {
      the_same_flowers.push_back(data[i]);
    }
  }
  return the_same_flowers;
}

int CalculateFlowers(int sum, const std::pair<Shape,FlowerBed>& flowerbed_pair){
  if(flowerbed_pair.first==CIRCLE){
    return sum+flowerbed_pair.second.GetFlowers().size();
  }
  return sum;
}

int GreenHouse::FlowersInCircleFbed(const multimap<Shape,FlowerBed>& flower_bed_map) {
  return std::accumulate(flower_bed_map.begin(), flower_bed_map.end(), 0, CalculateFlowers);

  /*Shape shape = CIRCLE;
  int amount = 0;
  auto iterator = find_if(data.begin(), data.end(),CompareWithShape);
  if (iterator == data.end()) {
    return amount;
  } else {
    amount += iterator->GetFlowers().size();
  }

  while (iterator != data.end()) {
    iterator = find_if(iterator+1, data.end(),CompareWithShape);
    amount += iterator->GetFlowers().size();
  }
  return amount;*/
}


vector<FlowerBed> GreenHouse::FbedsWithAmountOfFlowers(vector<FlowerBed> data,int amount) {
  vector<FlowerBed> fbeds_with_amount;
  CompareWithAmount compare(amount);
  auto iterator=find_if(data.begin(),data.end(),compare);
  if(iterator==data.end()){
    return fbeds_with_amount;
  }
  while(iterator!=data.end()){
    fbeds_with_amount.push_back(*iterator);
    iterator=find_if(iterator+1,data.end(),compare);
  }
  return fbeds_with_amount;
}



/*void GreenHouse::DeleteFlower(string flower) {
  for (int i = 0; i < data.size(); ++i) {
    vector<string>* flowers_in_bed=& data[i].get_flowers();
    auto iterator = find_if(flowers_in_bed.,
                            data[i].get_flowers().end(),
                            [flower](string flower_in_fbed) { return flower == flower_in_fbed; });
    while (iterator != data[i].get_flowers().end()) {
      data[i].get_flowers().erase(iterator);
      iterator = find_if(iterator + 1,
                         data[i].get_flowers().end(),
                         [flower](string flower_in_fbed) { return flower == flower_in_fbed; });
    }
  }
}*/
  /*for(int i=0;i<data.size();++i){
  auto iterator = find_if(data.begin(), data.end(),
                          [flower](FlowerBed flower_bed){
    for(int i=0;i<flower_bed.get_flowers().size();++i){
      if(flower_bed.get_flowers()[i]==flower){
        return true;
      }
    }
    return false;
  });

  while (iterator != data.end()) {
    iterator->get_flowers().;
    iterator = find_if(iterator+1, data.end(),[flower](FlowerBed flower_bed){
      for(int i=0;i<flower_bed.get_flowers().size();++i){
        if(flower_bed.get_flowers()[i]==flower){
          return true;
        }
      }
      return false;
    });
  }*/

