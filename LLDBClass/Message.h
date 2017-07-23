//
//  Message.h
//  Pods
//
//  Created by Lilong on 2017/7/23.
//
//

#import <Foundation/Foundation.h>
#import "WCTCoding.h"
#import "WCTCodingMacro.h"
//#import <WCDB/WCDB.h>

//Message.h
@interface Message : NSObject <WCTTableCoding>

@property int localID;
@property(retain) NSString *content;
@property(retain) NSDate *createTime;
@property(retain) NSDate *modifiedTime;
@property(assign) int unused; //You can just define the properties you need

//使用WCDB_PROPERTY宏在头文件声明需要绑定到数据库表的字段。
WCDB_PROPERTY(localID)
WCDB_PROPERTY(content)
WCDB_PROPERTY(createTime)
WCDB_PROPERTY(modifiedTime)

@end
