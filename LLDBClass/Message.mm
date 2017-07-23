//
//  Message.m
//  Pods
//
//  Created by Lilong on 2017/7/23.
//
//

#import "Message.h"
#import <WCDB/WCDB.h>

//Message.mm
@implementation Message

//使用WCDB_IMPLEMENTATIO宏在类文件定义绑定到数据库表的类。
WCDB_IMPLEMENTATION(Message)

//使用WCDB_SYNTHESIZE宏在类文件定义需要绑定到数据库表的字段
WCDB_SYNTHESIZE(Message, localID)
WCDB_SYNTHESIZE(Message, content)
WCDB_SYNTHESIZE(Message, createTime)
WCDB_SYNTHESIZE(Message, modifiedTime)

//WCDB_PRIMARY用于定义主键
WCDB_PRIMARY(Message, localID)
//WCDB_INDEX用于定义索引
WCDB_INDEX(Message, "_index", createTime)
//WCDB_UNIQUE用于定义唯一约束
//WCDB_NOT_NULL用于定义非空约束
@end
