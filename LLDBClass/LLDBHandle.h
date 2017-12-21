//
//  LLDBHandle.h
//  Pods
//
//  Created by Lilong on 2017/7/23.
//
//

#import <Foundation/Foundation.h>
#import "WCTDeclare.h"

@interface LLDBHandle : NSObject
#pragma mark - creat  创建

/**
 获取创建数据的文件目录
 
 @param dbName 数据库名称
 @return 文件目录
 */
+ (NSString *)getCreatDBFilepathWithDBName:(NSString *)dbName;

/**
 可创建表和索引
 
 @param tableName 表格名称
 @param cls 表格的model class
 @param dbPath 数据库路径
 @return 是否创建成功
 */
+ (BOOL)createTableAndIndexesOfName:(NSString *)tableName
                          withClass:(Class<WCTTableCoding>)cls
                             dbPath:(NSString *)dbPath;
#pragma mark - Insert  插入数据
/**
 插入数据库 单条
 
 @param object 数据model
 @param tableName 表格名称
 @param dbPath 数据库路径
 @return 是否插入成功
 */
+ (BOOL)insertObject:(WCTObject *)object
                into:(NSString *)tableName
              dbPath:(NSString *)dbPath;

/**
 插入数据  多条
 */
+ (BOOL)insertObjects:(NSArray<WCTObject *> *)objects
                 into:(NSString *)tableName
               dbPath:(NSString *)dbPath;
/**
 插入数据  单条 去重复
 */
+ (BOOL)insertOrReplaceObject:(WCTObject *)object
                         into:(NSString *)tableName
                       dbPath:(NSString *)dbPath;
/**
 插入数据  多条 去重复
 */
+ (BOOL)insertOrReplaceObjects:(NSArray<WCTObject *> *)objects
                          into:(NSString *)tableName
                        dbPath:(NSString *)dbPath;

#pragma mark - Delete

/**
 删除数据  全部
 
 @param tableName 表格名称
 @param dbPath 数据库路径
 @return 是否成功
 */
+ (BOOL)deleteAllObjectsFromTable:(NSString *)tableName
                           dbPath:(NSString *)dbPath;
/**
 删除数据
 
 @param tableName 表格名称
 @param condition where条件
 @param dbPath 数据库路径
 @return 是否成功
 */
+ (BOOL)deleteObjectsFromTable:(NSString *)tableName
                         where:(const WCTCondition &)condition
                        dbPath:(NSString *)dbPath;

/**
 删除数据
 
 @param tableName 表格名称
 @param condition where条件
 @param orderList 根据什么属性字段排序
 @param limit  limit -> Y是选取Y个数据
 @param offset offset -> X是跳过X个数据
 @param dbPath 数据库路径
 @return 是否删除成功
 */
+ (BOOL)deleteObjectsFromTable:(NSString *)tableName
                         where:(const WCTCondition &)condition
                       orderBy:(const WCTOrderByList &)orderList
                         limit:(const WCTLimit &)limit
                        offset:(const WCTOffset &)offset
                        dbPath:(NSString *)dbPath;

#pragma mark - Update Properties With Object 更新

/**
 修改 某个表格中 某一个属性值 （所有）
 
 @param tableName 表格名称
 @param propertyList 属性值
 @param object model类型
 @param dbPath 数据库路径
 @return 是否修改成功
 */
+ (BOOL)updateAllRowsInTable:(NSString *)tableName
                onProperties:(const WCTPropertyList &)propertyList
                  withObject:(WCTObject *)object
                      dbPath:(NSString *)dbPath;

/**
 修改 表格中的 某个数据的值  （条件 ）
 */
+ (BOOL)updateRowsInTable:(NSString *)tableName
             onProperties:(const WCTPropertyList &)propertyList
               withObject:(WCTObject *)object
                    where:(const WCTCondition &)condition
                   dbPath:(NSString *)dbPath;

+ (BOOL)updateRowsInTable:(NSString *)tableName
             onProperties:(const WCTPropertyList &)propertyList
               withObject:(WCTObject *)object
                    where:(const WCTCondition &)condition
                  orderBy:(const WCTOrderByList &)orderList
                    limit:(const WCTLimit &)limit
                   offset:(const WCTOffset &)offset
                   dbPath:(NSString *)dbPath;
#pragma mark - Get Objects 查询

/**
 获取某个表格的所以数据
 
 @param cls class
 @param tableName 表格名字
 @param dbPath 数据库路径
 @return 结果
 */
+ (NSArray /* <WCTObject*> */ *)getAllObjectsOfClass:(Class)cls
                                           fromTable:(NSString *)tableName
                                              dbPath:(NSString *)dbPath;

+ (NSArray /* <WCTObject*> */ *)getObjectsOfClass:(Class)cls
                                        fromTable:(NSString *)tableName
                                            where:(const WCTCondition &)condition
                                           dbPath:(NSString *)dbPath;

/**
 查询数据
 
 @param cls 类型
 @param tableName 表名称
 @param condition where
 @param orderList 按照某个字段排序
 @param limit 限制个数
 @param offset offset X是跳过X个数据
 @param dbPath 数据库路径
 @return 返回结果
 */
+ (NSArray /* <WCTObject*> */ *)getObjectsOfClass:(Class)cls
                                        fromTable:(NSString *)tableName
                                            where:(const WCTCondition &)condition
                                          orderBy:(const WCTOrderByList &)orderList
                                            limit:(const WCTLimit &)limit
                                           offset:(const WCTOffset &)offset
                                           dbPath:(NSString *)dbPath;


@end
