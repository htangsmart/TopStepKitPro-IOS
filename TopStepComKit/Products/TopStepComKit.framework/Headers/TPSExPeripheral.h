//
//  ExPeripheral.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/20.
//

#ifndef TPSExPeripheral_h
#define TPSExPeripheral_h

#import <CoreBluetooth/CoreBluetooth.h>

@interface TPSExPeripheral : NSObject

@property(nonatomic, strong, nullable) CBPeripheral *peripheral;
//确实有一种拿不到mac的情况，如果用户连接成功后，又卸载app，此时系统的ble还连接，然后用户再次安装app，扫描的时候不会扫描到（因为属于还在系统连接中的），这时候就怎么也拿不到mac。（要考虑绑定成功后通过js返回mac）
@property(nonatomic, strong) NSString* mac;
@property(nonatomic, strong) NSString* name;
@property(nonatomic, strong, nullable) NSNumber* RSSI;
@property(nonatomic, strong, nullable) NSDictionary<NSString *,id>* advertisementData;
@property(nonatomic, strong, nullable) CBCentralManager* central;

-(instancetype)initWithPeripheral:(CBPeripheral*)peripheral mac:(NSString*)mac name:(NSString*)name RSSI:(NSNumber*)RSSI advertisementData:(NSDictionary<NSString *,id>*) advertisementData central:(CBCentralManager*)central;

@end


#endif /* ExPeripheral_h */
