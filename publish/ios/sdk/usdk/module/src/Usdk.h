#import "UsdkBase.h"
#import "UsdkApplicationDelegate.h"

#define PLATFORM_NAME               @"PlatformProxy"
typedef void (*UsdkCallBackListener_Callback)(const char* callbackName, const char* jsonMsg);

@interface Usdk : NSObject
+(Usdk*) instance;
@property(nonatomic, assign) UsdkCallBackListener_Callback usdkCallback;
@property NSMutableDictionary *m_pluginMap;
@property UIApplication *m_application;
@property NSDictionary *m_launchOptions;
- (void)callPlugin:(NSString*)pluginName methodName:(NSString*)methodName with:(NSArray*) args;
- (NSString*)callPluginR:(NSString*)pluginName methodName:(NSString*)methodName with:(NSArray*) args;
- (UsdkBase*)loadPlugin:(NSString*)pluginName;
- (BOOL)isExistPlugin:(NSString*)pluginName;
- (BOOL)isExistMethod:(NSString*)pluginName methodName:(NSString*)methodName;

- (BOOL)application:(UIApplication *)application openURL:(NSURL *)url sourceApplication:(NSString *)sourceApplication annotation:(id)annotation NS_AVAILABLE_IOS(4_2);
- (BOOL)application:(UIApplication *)application willFinishLaunchingWithOptions:(NSDictionary *)launchOptions;
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions ;
- (void)applicationWillResignActive:(UIApplication *)application ;
- (void)applicationDidBecomeActive:(UIApplication *)application;
- (void)applicationWillEnterForeground:(UIApplication *)application ;
- (void)applicationDidEnterBackground:(UIApplication *)application ;
- (void)applicationWillTerminate:(UIApplication *)application ;
- (void)applicationDidReceiveMemoryWarning:(UIApplication *)application;
- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken ;
- (void)application:(UIApplication*)application didFailToRegisterForRemoteNotificationsWithError:(NSError*)error;
- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo ;
- (void)application:(UIApplication *)application supportedInterfaceOrientationsForWindow:(UIWindow *)window;
@end
