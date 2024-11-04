//
//  IWearDevInfoSync.h
//  JieliJianKang
//
//  Created by Topstep on 2023/12/16.
//

#ifndef ITPSDevInfoAbility_h
#define ITPSDevInfoAbility_h

#import <TopStepComKit/ITPSWearBaseAbility.h>
#import <TopStepComKit/TPSWearBlockTypeDef.h>
#import <TopStepComKit/TPSDevInfoModel.h>
//#import <ReactiveObjC.h>

typedef NS_OPTIONS(NSInteger, TPSFunctionType) {
    TPSFunctionTypeNone            = 0,
    
    // 设备页
    TPSFunctionTypeContactBook     = 1 << 0,   ///< 联系人
    TPSFunctionTypeCardPocket      = 1 << 1,   ///< 卡包
    TPSFunctionTypeFindWatch       = 1 << 2,   ///< 查找手表
    TPSFunctionTypeWeather         = 1 << 3,   ///< 天气推送
    TPSFunctionTypeMessageNotifacation = 1 << 4, ///< 消息通知
    TPSFunctionTypeAlarmClock      = 1 << 5,   ///< 手表闹钟
    TPSFunctionTypeMusic           = 1 << 6,   ///< 音乐推送
    TPSFunctionTypeRemind          = 1 << 7,   ///< 提醒设置
    TPSFunctionTypeDeviceSetting   = 1 << 8,   ///< 设备设置
    TPSFunctionTypePhoto           = 1 << 9,   ///< 相册
    TPSFunctionTypeBook            = 1 << 10,   ///< 电子书
    TPSFunctionTypeNavigation      = 1 << 11,  ///< 导航
    TPSFunctionTypeGame            = 1 << 12,  ///< 体感游戏
    TPSFunctionTypeTakePhoto       = 1 << 13,  ///< 摇一摇拍照
    
    // 健康页
    TPSFunctionTypeHearRate        = 1 << 14,  ///< 心率
    TPSFunctionTypeStepCount       = 1 << 15,  ///< 步数
    TPSFunctionTypeSportRecord     = 1 << 16,  ///< 运动记录
    TPSFunctionTypeSleep           = 1 << 17,  ///< 睡眠
    TPSFunctionTypeWeightManager   = 1 << 18,  ///< 体重管理
    TPSFunctionTypeStress          = 1 << 19,  ///< 压力
    TPSFunctionTypeBloodOxy        = 1 << 20,  ///< 血氧
    TPSFunctionTypeBloodPress      = 1 << 21,  ///< 血压
    TPSFunctionTypeFemalHealth     = 1 << 22,  ///< 女性健康
    TPSFunctionTypeElectrocardiogram = 1 << 23,  ///< 心电
    TPSFunctionTypeBodyTemprature  = 1 << 24,  ///< 体温
};


@class RACSubject<ValueType>;
@protocol ITPSDevInfoAbility <NSObject,ITPSWearBaseAbility>

+(instancetype)share;

-(RACSubject<TPSDevInfoModel*>*)getDevInfo;

-(RACSubject<NSNumber*>*)observeBattery;

- (void)getCurrentBattery:(void(^)(CGFloat battery))success;

-(void)resetToFactoryState:(TPSSendMsgResult _Nullable)block;

-(TPSDevInfoModel*)getExistDevInfo;

-(void)sendPhoneSystemTime;

- (RACSubject*)restartPeripheral;

- (RACSubject*)shutdownPeripheral;

- (void)updateBattery:(CGFloat)batteryValue;

/// 获取设备是否支持某个功能
- (void)getSupportedByFunctionType:(TPSFunctionType)type result:(void(^)(BOOL supported ,NSError *error))result;
/// 获取设备支持的所有功能
- (void)getAllSupportedFunction:(void(^)(TPSFunctionType supportedFunctions, NSError *error))result;

@end


#endif /* IWearDevInfoSync_h */
