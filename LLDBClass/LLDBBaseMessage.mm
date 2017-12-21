//
//  LLDBBaseMessage.m
//  Pods
//
//  Created by Lilong on 2017/7/23.
//
//

#import "LLDBBaseMessage.h"
#import <WCDB/WCDB.h>

//Message.mm
@implementation LLDBBaseMessage


//使用WCDB_IMPLEMENTATIO宏在类文件定义绑定到数据库表的类。
WCDB_IMPLEMENTATION(LLDBBaseMessage)

//使用WCDB_SYNTHESIZE宏在类文件定义需要绑定到数据库表的字段
WCDB_SYNTHESIZE(LLDBBaseMessage, localID)
WCDB_SYNTHESIZE(LLDBBaseMessage, content)
WCDB_SYNTHESIZE(LLDBBaseMessage, createTime)
WCDB_SYNTHESIZE(LLDBBaseMessage, modifiedTime)

//WCDB_PRIMARY用于定义主键
WCDB_PRIMARY(LLDBBaseMessage, localID)
//WCDB_INDEX用于定义索引
WCDB_INDEX(LLDBBaseMessage, "_index", createTime)
//WCDB_UNIQUE用于定义唯一约束
//WCDB_NOT_NULL用于定义非空约束
@end
