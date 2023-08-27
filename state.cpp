#include<iostream>
#include<map>
#include<string>
class DownLoadManager;
class State {
 public:
  virtual void DownLoadOperate(std::string user, std::string item, DownLoadManager *ptr) = 0;
//  protected:
//   State(){};
};
class NormalDownLoad : public State {
 public:
  void DownLoadOperate(std::string user, std::string item, DownLoadManager *ptr) {
    std::cout << "正常下载" << std::endl;
  }
};
class RepeatDownLoad : public State {
 public:
  void DownLoadOperate(std::string user, std::string item, DownLoadManager *ptr) {
    std::cout << "重复下载" << std::endl;
  }
};
class SpiteDownLoad : public State {
 public:
  void DownLoadOperate(std::string user, std::string item, DownLoadManager *ptr) {
    std::cout << "恶意下载" << std::endl;
  }
};
class BlackDownLoad : public State {
 public:
  void DownLoadOperate(std::string user, std::string item, DownLoadManager *ptr) {
    std::cout << "黑名单下载" << std::endl;
  }
};
class DownLoadManager {
    public:
    void DownLoad(std::string username,std::string downloaditem){
        int download_count=0;
        if(username_download_counter_.count(username)>0){
            download_count=username_download_counter_[username];
        }else{
            username_download_counter_[username]=0;
        }
        download_count++;
        username_download_counter_[username]=download_count;
        if(download_count==1){
            state_ptr_=new NormalDownLoad();
        }else if( download_count>1 && download_count<3){
            state_ptr_=new RepeatDownLoad();
        }else if(download_count>=3 && download_count<5){
            state_ptr_=new SpiteDownLoad();
        }else if( download_count>=5){
            state_ptr_=new BlackDownLoad();
        }
        state_ptr_->DownLoadOperate(username,downloaditem,this);
    }
    private:
    std::map<std::string,std::string> username_download_item_;
    std::map<std::string,int> username_download_counter_;
    State * state_ptr_;
};
int main(){
    DownLoadManager * ptr=new DownLoadManager();
    for(int i=0;i<4;i++){
        ptr->DownLoad("WLK","XiaoMing");//调用中改变了下载次数
    }
    return 0;
}
