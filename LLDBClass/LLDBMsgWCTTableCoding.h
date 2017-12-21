//
//  LLDBMsgWCTTableCoding.h
//  Pods
//
//  Created by Lilong on 2017/8/20.
//
//

#import <Foundation/Foundation.h>
#import <WCDB/WCDB.h>
#import "LLDBMsg.h"
@interface LLDBMsg (WCTTableCoding)<WCTTableCoding>
WCDB_PROPERTY(test1)
WCDB_PROPERTY(test2)
@end
