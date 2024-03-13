
/*
 * Copyright (C) Igor Sysoev
 * Copyright (C) Nginx, Inc.
 */


#ifndef _NGX_CORE_H_INCLUDED_
#define _NGX_CORE_H_INCLUDED_


#include <ngx_config.h>

typedef struct ngx_module_s ngx_module_t;                    /// Nginx模块的结构体，用于表示不同的Nginx模块，如HTTP模块、事件模块等。
typedef struct ngx_conf_s ngx_conf_t;                        /// 用于存储Nginx配置项解析和处理过程中的状态信息的结构体。
typedef struct ngx_cycle_s ngx_cycle_t;                      /// Nginx运行时的主要环境的结构体，包括配置信息、日志信息、监听端口等。
typedef struct ngx_pool_s ngx_pool_t;                        /// Nginx的内存池的结构体，用于分配和管理内存。
typedef struct ngx_chain_s ngx_chain_t;                      /// 用于在Nginx中表示一个链表，通常用于在处理HTTP请求或响应时管理数据的链式结构。
typedef struct ngx_log_s ngx_log_t;                          /// Nginx的日志系统的结构体，用于记录程序运行时的日志信息。
typedef struct ngx_open_file_s ngx_open_file_t;              /// 用于在Nginx中表示一个已打开的文件，主要用于日志文件的管理。
typedef struct ngx_command_s ngx_command_t;                  /// 代表一个Nginx配置指令的结构体，用于配置文件中的指令解析。
typedef struct ngx_file_s ngx_file_t;                        /// 代表一个文件的结构体，在Nginx中用于文件的操作和管理。
typedef struct ngx_event_s ngx_event_t;                      /// 代表一个事件的结构体，在Nginx的事件驱动模型中，事件是程序运行的基本单位。
typedef struct ngx_event_aio_s ngx_event_aio_t;              /// 用于在Nginx中表示异步I/O事件的结构体。
typedef struct ngx_connection_s ngx_connection_t;            /// 代表一个连接的结构体，用于管理客户端和服务器之间的连接。
typedef struct ngx_thread_task_s ngx_thread_task_t;          /// 代表一个线程任务的结构体，在Nginx中用于多线程任务的管理。
typedef struct ngx_ssl_s ngx_ssl_t;                          /// 在Nginx中表示SSL/TLS的相关信息的结构体。
typedef struct ngx_proxy_protocol_s ngx_proxy_protocol_t;    /// 用于在Nginx中表示代理协议的相关信息的结构体。
typedef struct ngx_quic_stream_s ngx_quic_stream_t;          /// 用于在Nginx中表示QUIC流的相关信息的结构体。
typedef struct ngx_ssl_connection_s ngx_ssl_connection_t;    /// 代表一个SSL连接的结构体，在Nginx中用于管理SSL连接。
typedef struct ngx_udp_connection_s ngx_udp_connection_t;    /// 代表一个UDP连接的结构体，在Nginx中用于管理UDP连接。

typedef void (*ngx_event_handler_pt)(ngx_event_t *ev);
typedef void (*ngx_connection_handler_pt)(ngx_connection_t *c);


#define  NGX_OK          0
#define  NGX_ERROR      -1
#define  NGX_AGAIN      -2
#define  NGX_BUSY       -3
#define  NGX_DONE       -4
#define  NGX_DECLINED   -5
#define  NGX_ABORT      -6


#include <ngx_errno.h>
#include <ngx_atomic.h>
#include <ngx_thread.h>
#include <ngx_rbtree.h>
#include <ngx_time.h>
#include <ngx_socket.h>
#include <ngx_string.h>
#include <ngx_files.h>
#include <ngx_shmem.h>
#include <ngx_process.h>
#include <ngx_user.h>
#include <ngx_dlopen.h>
#include <ngx_parse.h>
#include <ngx_parse_time.h>
#include <ngx_log.h>
#include <ngx_alloc.h>
#include <ngx_palloc.h>
#include <ngx_buf.h>
#include <ngx_queue.h>
#include <ngx_array.h>
#include <ngx_list.h>
#include <ngx_hash.h>
#include <ngx_file.h>
#include <ngx_crc.h>
#include <ngx_crc32.h>
#include <ngx_murmurhash.h>
#if (NGX_PCRE)
#include <ngx_regex.h>
#endif
#include <ngx_radix_tree.h>
#include <ngx_times.h>
#include <ngx_rwlock.h>
#include <ngx_shmtx.h>
#include <ngx_slab.h>
#include <ngx_inet.h>
#include <ngx_cycle.h>
#include <ngx_resolver.h>
#if (NGX_OPENSSL)
#include <ngx_event_openssl.h>
#if (NGX_QUIC)
#include <ngx_event_quic.h>
#endif
#endif
#include <ngx_process_cycle.h>
#include <ngx_conf_file.h>
#include <ngx_module.h>
#include <ngx_open_file_cache.h>
#include <ngx_os.h>
#include <ngx_connection.h>
#include <ngx_syslog.h>
#include <ngx_proxy_protocol.h>
#if (NGX_HAVE_BPF)
#include <ngx_bpf.h>
#endif


#define LF     (u_char) '\n'
#define CR     (u_char) '\r'
#define CRLF   "\r\n"


#define ngx_abs(value)       (((value) >= 0) ? (value) : - (value))
#define ngx_max(val1, val2)  ((val1 < val2) ? (val2) : (val1))
#define ngx_min(val1, val2)  ((val1 > val2) ? (val2) : (val1))

void ngx_cpuinfo(void);

#if (NGX_HAVE_OPENAT)
#define NGX_DISABLE_SYMLINKS_OFF        0
#define NGX_DISABLE_SYMLINKS_ON         1
#define NGX_DISABLE_SYMLINKS_NOTOWNER   2
#endif

#endif /* _NGX_CORE_H_INCLUDED_ */
