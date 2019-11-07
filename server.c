#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdio.h>
#include<stdlib.h>
#include <errno.h>
#include <error.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include<stdlib.h>
# include <sys/ipc.h>
# include <sys/msg.h>

int main()
{
  int msqid;  /* IPC дескриптор для очереди сообщений */
  char pathname[] = "msg1.c";     /* Имя файла, использующееся для генерации ключа. Файл с таким именем должен существовать в текущей директории */
  key_t key; /* IPC ключ */
  int i,len; /* Счетчик цикла и длина информативной части сообщения */
  int Pid = getpid();



  struct receive_msg
  {
    long mtype;
    int res;
  };

  struct send_msg
  {
    long mtype;
    int res;
  };

  struct mymsgbuf
  {
    long mtype;
    int a,b;
    int id;
    int res;
    char mtext[81];
  } mybuf;


  /* Генерируем IPC ключ из имени файла msg1.c в текущей
  директории и номера экземпляра очереди сообщений 0. */
  if((key = ftok(pathname,0)) < 0)
  {// генерация IPC ключа
      printf("Can\'t generate key\n");
      exit(-1);
  }


  if((msqid = msgget(key, 0666 | IPC_CREAT)) < 0)/* Пытаемся получить доступ по ключу к очереди сообщений, если она существует, или создать ее, с правами доступа read & write для всех пользователей */
  {
      printf("Can\'t get msqid\n");
        exit(-1);
  }
  /* Посылаем в цикле 5 сообщений с типом 1
в очередь сообщений, идентифицируемую msqid.*/






int msqidm;  /* IPC дескриптор для очереди сообщений */
char pathnamez[] = "msg2.c";     /* Имя файла, использующееся для генерации ключа. Файл с таким именем должен существовать в текущей директории */
key_t keym; /* IPC ключ */

  if((keym = ftok(pathnamez,0)) < 0)
  {// генерация IPC ключа
    printf("Can\'t generate key\n");
    exit(-1);
  }


  if((msqidm = msgget(keym, 0666 | IPC_CREAT)) < 0)/* Пытаемся получить доступ по ключу к очереди сообщений, если она существует, или создать ее, с правами доступа read & write для всех пользователей */
  {
    printf("Can\'t get msqid\n");
      exit(-1);
  }






  fork();
  if(getpid() != Pid)
  {
    struct receive_msg received_msg;
  /* Сначала заполняем структуру для нашего
  сообщения и определяем длину информативной части */
      mybuf.mtype = getpid();
      mybuf.a = getpid();
      mybuf.b = 3;
      strcpy(mybuf.mtext, " is text message");
      len = strlen(mybuf.mtext)+1+ 3*sizeof(int);
  /* Отсылаем сообщение. В случае ошибки сообщаем об
  этом и удаляем очередь сообщений из системы. */
      if(msgsnd(msqid, (struct msgbuf *) &mybuf, len, 0) < 0){
        printf("Can\'t send message to queue\n");
        msgctl(msqid, IPC_RMID, (struct msqid_ds *) NULL);
        exit(-1);
      }




  int  maxlen = 81;

    if( len = msgrcv(msqidm, (struct receive_msg *) &received_msg, maxlen, getpid(), 0) < 0){
      printf("Can\'t receive message from queue\n");
      exit(-1);
    }

  //  printf("%d %d\n", getpid(), sendind_msg.res);

/* Если принятое сообщение имеет тип LAST_MESSAGE,
прекращаем работу и удаляем очередь сообщений из
системы. В противном случае печатаем текст принятого
сообщения. */
  }
  else
  {

    struct mbuf
    {
      long mtype;
      int a,b;
      int id;
      int res;
      char mtext[81];
    } buf;



struct send_msg sending_msg;
    while(1){

    //  struct send_msg sending_msg;


/* В бесконечном цикле принимаем сообщения
любого типа в порядке FIFO с максимальной длиной информативной
части 81 символ до тех пор, пока не поступит сообщение с
  типом LAST_MESSAGE*/
    int  maxlen = 81;
      if( (len = msgrcv(msqid, (struct mbuf *) &buf, maxlen, 0, 0)) < 0){
        printf("Can\'t receive message from queue\n");
        exit(-1);
      }
      buf.res = buf.a*buf.b;
/* Если принятое сообщение имеет тип LAST_MESSAGE,
прекращаем работу и удаляем очередь сообщений из
системы. В противном случае печатаем текст принятого
сообщения. */

      printf("message type = %ld, info = %s\n", mybuf.mtype, mybuf.mtext);
    }

  /* Сначала заполняем структуру для нашего
    сообщения и определяем длину информативной части */



      sending_msg.mtype = buf.mtype;
      sending_msg.res = buf.a*buf.b;

    len = sizeof(int) + 1;
    /* Отсылаем сообщение. В случае ошибки сообщаем об
    этом и удаляем очередь сообщений из системы. */
      if(msgsnd(msqidm, (struct send_msg *) &sending_msg, len, 0) < 0){
        printf("Can\'t send message to queue\n");
        msgctl(msqidm, IPC_RMID, (struct msqid_ds *) NULL);
        exit(-1);
      }




  }


















  /* Отсылаем сообщение, которое заставит получающий процесс
прекратить работу, с типом LAST_MESSAGE и длиной 0 */


  return 0;





}
