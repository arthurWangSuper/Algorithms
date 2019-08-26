std::vector<SP_Channel> Epoll::getEventsRequest(int events_num)
{
    std::vector<SP_Channel> req_data;
    for(int i=0;i<events_num;++i){
        //获取有事件产生的描述符
        int fd = events_[i].data.fd;

        SP_Channel cur_req = fd2chan_[fd];
        if(cur_req){
            cur_req->setRevents(events_[i].events);
            cur_req->setEvents(0);
            //加入线程池之前，将Timer和request分离
            //cur_req->seperateTimer();
            req_data.push_back(cur_req);
        }else
        {
            LOG<<"SP cur_req is invalid";
        }
        
    }
    return req_data;
}