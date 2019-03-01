void err_sys (char *fmt, ...);
void err_quit (char *fmt, ...);
void sock_set_port(struct sockaddr *sa, socklen_t salen, int port);
int sock_cmp_addr(const struct sockaddr *sa1,
        const struct sockaddr *sa2, socklen_t salen);
void tv_sub (struct timeval *out, struct timeval *in);
char *icmpcode_v4(int code);
struct addrinfo *Host_serv(const char *host, const char *serv,
        int family, int socktype);
ssize_t Read(int fd, void *ptr, size_t nbytes);
void Write(int fd, void *ptr, size_t nbytes);
ssize_t Recvfrom(int fd, void *ptr, size_t nbytes, int flags,
        struct sockaddr *sa, socklen_t *salenptr);
