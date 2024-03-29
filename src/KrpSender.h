/*
** ClientWriter.h for redis-protocol in /home/pi/redis-protocol
**
** Made by solidest
** Login   <solidest>
**
** Started on  undefined Oct 20 3:18:01 PM 2019 solidest
** Last update Fri Oct 24 6:29:24 PM 2019 solidest
*/

#ifndef _CLIENTWRITER_H_
# define _CLIENTWRITER_H_

#include "sds.h"


#define KRP_ERR -1
#define KRP_OK 0

typedef void SendHandle(sds buf);

class KrpSender {

    public:
        KrpSender(SendHandle* psender);
        int FormatCommand(sds * target, int argc, const char ** argv, const size_t *argvlen);
        void SendCommand(int argc, const char ** argv, const size_t *argvlen);
        void SendError(const char* err);

    private:
        SendHandle* _psender;
};


#endif /* !_CLIENTWRITER_H_ */
