#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>

int n = 0;

void CreatureChildren(int* tree, int Id) {
  for (int i = 0; i < n; i++) {
    if (tree[i] == Id) {
      pid_t res = fork();
      if (res == 0) {
        spawnChildren(tree, i);
        return;
      }
      else if (res > 0) {
        printf(" tree id: %d\t parent tree id: %d\t pid: %d\t ppid: %d\n",
        i, Id, res, getpid());
      }
      else {
        puts("Error");
        return;
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  pid_t rootPid = getpid();
  scanf("%d", &n);
  int* tree = (int*)malloc(sizeof(int) * n);
  for (int* ptr = tree; ptr < tree + n; ptr++) {
    scanf("%d", ptr);
  }
  CreatureChildren(tree, -1);
  free(tree);
  pid_t wpid;
  int stat = -1;
  while ((wpid = wait(&stat)) > 0);
  if (getpid() == rootPid)
    puts("Ok. Wait...");
  return 0;
}
